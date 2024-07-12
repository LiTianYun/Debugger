#include "wavepage.h"
#include "ui_wavepage.h"
#include "legenditemdialog.h"
#include "widget.h"

wavepage::wavepage(Widget *parent, SerialPort *Port) :
    QWidget(nullptr),
    ui(new Ui::wavepage),
    recordMap(*(new QMap<QString, double>)),
    plotMap(*(new QMap<QString, int>))
{
    ui->setupUi(this);
    parentWidget = parent;  // 父窗口指针
    serialPort = Port;    // 串口指针
    // recordMap初始化为空
    recordMap.clear();
    plotMap.clear();

    doubleRegex = new QRegularExpression("-?\\d*\\.?\\d+"); // 正则表达式 限制输入为整数或小数
    doubleRegex->optimize();    // 优化正则表达式
    Init_wavepage();    // 初始化绘图界面
}

wavepage::~wavepage()
{
    if (!recordMap.isEmpty() && &recordMap) delete &recordMap;
    if (!plotMap.isEmpty() && &plotMap) delete &plotMap;
    delete ui;
}

void wavepage::Init_wavepage()
{
    // 变量初始化
    plotBuf = new QString();                        // 绘图数据缓存
    plotTracer = new QCPItemTracer(ui->qcpWidget);  // 绘图追踪器
    plotText = new QCPItemText(ui->qcpWidget);      // 绘图追踪器文本
    plotDefaultTicker = ui->qcpWidget->xAxis->ticker(); // 绘图默认X轴刻度
    plotCounter = 0;                                // 绘图计数器初始化为0
    plotXAxisWidth = ui->qcpWidget->xAxis->range().size();  // 获取X轴宽度
    plotTimeTicker->setTimeFormat("%h:%m:%s.%z");   // 设置时间格式
    plotTimeTicker->setTickCount(5);                // 设置刻度数量

    // 默认项
    // parentWidget->Button_Switch(ui->Serial_Wave_New, true);       // 自动跟随最新数据
    // parentWidget->Button_Switch(ui->Serial_Wave_Zoom, true);      // 启用缩放
    ui->qcpWidget->axisRect()->setRangeZoom(Qt::Horizontal);    // 默认X轴缩放


    // 绑定ctrl为Y轴缩放
    connect(this, &wavepage::myKeyPressSignal, [=](QKeyEvent *event){
        // 如果为ctrl键
        if(event->key() == Qt::Key_Control)
        {
            ui->qcpWidget->axisRect()->setRangeZoom(Qt::Vertical);  // 设置Y轴缩放
            ui->Serial_Wave_Zoom->setText(tr("Y轴缩放"));
        }
    });
    // 松开ctrl后恢复X轴缩放
    connect(this, &wavepage::myKeyReleaseSignal, [=](QKeyEvent *event){
        // 如果为ctrl键
        if(event->key() == Qt::Key_Control)
        {
            ui->qcpWidget->axisRect()->setRangeZoom(Qt::Horizontal);    // 设置X轴缩放
            ui->Serial_Wave_Zoom->setText(tr("X轴缩放"));
        }
    });

    plotTime = QTime();                        // 初始化时间戳
    

    // 数据处理定时器初始化
    m_dataProcessTimer = new QTimer();              // 数据处理定时器
    connect(m_dataProcessTimer, &QTimer::timeout, this, &wavepage::processData); // 绑定数据处理定时器到绘图函数
    m_dataProcessTimer->setInterval(1);            // 设置定时器间隔 10ms
    m_dataProcessTimer->start();                    // 启动定时器

    // 绘图外观初始化
    ui->qcpWidget->axisRect()->setupFullAxesBox(true);  // 设置坐标轴范围自适应
    ui->qcpWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectLegend | QCP::iSelectPlottables);    // 设置交互方式 启用交互功能
    // ui->qcpWidget->legend->setSelectableParts(QCPLegend::spItems);  // 设置图例可选部分
    ui->qcpWidget->legend->setVisible(true);    // 设置图例可见

    // 跟踪器设置
    plotTracer->setStyle(QCPItemTracer::tsCrosshair);   // 设置跟踪器样式为十字
    plotTracer->setBrush(Qt::red);          // 设置跟踪器画刷为红色
    plotTracer->setInterpolating(false);    // 关闭跟踪器插值
    plotTracer->setVisible(false);          // 隐藏跟踪器

    // 跟踪器文本设置
    plotText->setPositionAlignment(Qt::AlignTop | Qt::AlignLeft);   // 设置文本位置
    plotText->setTextAlignment(Qt::AlignLeft);  // 设置文本对齐方式
    plotText->position->setType(QCPItemPosition::ptAxisRectRatio);  // 设置文本位置类型
    plotText->position->setCoords(0.02, 0.02);  // 设置文本位置坐标
    plotText->setPen(QPen(Qt::black));  // 设置文本画笔颜色
    // plotText->setPadding(QMargins(2, 2, 2, 2)); // 设置文本边距
    plotText->setVisible(false);    // 隐藏文本
    plotSelectedName = "";        // 初始化选中曲线名称为空
    ui->qcpWidget->replot(QCustomPlot::rpQueuedReplot); // 重绘图像    // 重绘绘制窗口

    // 设置图例透明度
    ui->qcpWidget->legend->setBrush(QBrush(QColor(255, 255, 255, 50))); // 设置图例画刷颜色
    ui->qcpWidget->legend->setBorderPen(Qt::NoPen); // 设置图例边框画笔颜色

    // 绑定信号槽
    connect(ui->qcpWidget, &QCustomPlot::selectionChangedByUser, this, &wavepage::onQCPSelectionChanged);    // 将选中曲线事件：同步图例的选中和曲线的选中
    connect(ui->qcpWidget->xAxis, QOverload<const QCPRange&>::of(&QCPAxis::rangeChanged), this, &wavepage::onXAxisChangedByUser); // 将X轴范围改变事件：存储X轴范围大小
    connect(ui->qcpWidget, &QCustomPlot::legendDoubleClick, this, &wavepage::onQCPLegendDoubleClick);    // 双击图例事件：隐藏/显示曲线
    connect(ui->qcpWidget, &QCustomPlot::legendClick, this, &wavepage::onQCPLegendClick);    // 单击图例事件：右键打开图例设置菜单
    
    qDebug() << "wavepage init finished!";
}

// 同步图例的选中和曲线的选中
void wavepage::onQCPSelectionChanged()
{
    // 如果on_Serial_Wave_ON_clicked()按钮开启，直接返回
    // if(parentWidget->Get_Button_Switch(ui->Serial_Wave_ON) == true)
    //     return;    
    
    QCPGraph *graph;
    // // 1. 同步图例和曲线的选中状态
    plotSelectedId = 0;
    for(int i = 0; i < ui->qcpWidget->graphCount(); ++i) //遍历所有曲线
    {
        graph = ui->qcpWidget->graph(i); //获取第 i 条曲线对应的 QCPGraph 类型对象
        QCPPlottableLegendItem *item = ui->qcpWidget->legend->itemWithPlottable(graph); //获取曲线在图例中对应的 QCPPlottableLegendItem 类型对象
        // 若该曲线被选中(曲线或图例),则同步曲线和图例的选中状态
        if(item->selected() || graph->selected())
        {
            if(ui->qcpWidget->legend->itemWithPlottable(graph)->plottable()->name()[0] == '*')   // 如果该曲线为隐藏状态
            {
                item->setSelected(false); //设置对应的图例项为不选中状态
            }else{
                plotSelectedId = i+1; //记录曲线id
                item->setSelected(true); //设置对应的图例项为选中状态
            }
        }
    }
    // 2. 判断是否有曲线被选中
    if(plotSelectedId)
    {
        // 2.1 启动指针显示
        Tracer_Switch(true);
        // 2.2 获取被选中的曲线
        graph = ui->qcpWidget->graph(plotSelectedId-1); 
        // 2.3 设置跟踪器目标为选中曲线
        plotTracer->setGraph(graph); 
        plotSelectedName = ui->qcpWidget->legend->itemWithPlottable(graph)->plottable()->name(); //获取被选中的曲线的名字
    }else{
        Tracer_Switch(false);
    }
}

// 取消所有曲线的选中状态
void wavepage::onQCPSelectionClear()
{
    // Copied from official interaction demo
    // A legendItem and a plottable cannot be both selected by user.
    // synchronize selection of graphs with selection of corresponding legend items:
    QCPGraph *graph;
    for(int i = 0; i < ui->qcpWidget->graphCount(); ++i) //遍历所有曲线
    {
        graph = ui->qcpWidget->graph(i); //获取第 i 条曲线对应的 QCPGraph 类型对象
        QCPPlottableLegendItem *item = ui->qcpWidget->legend->itemWithPlottable(graph); //获取曲线在图例中对应的 QCPPlottableLegendItem 类型对象
        // 若该曲线被选中(曲线或图例),则同步曲线和图例的选中状态
        if(item->selected() || graph->selected())
        {
            item->setSelected(false); //设置对应的图例项为不选中状态
            graph->setSelection(QCPDataSelection()); //设置该曲线的数据区域为不选中状态
        }
    }
    Tracer_Switch(false);   // 关闭指针显示
}

//

// 存储X轴范围大小
void wavepage::onXAxisChangedByUser(const QCPRange &newRange)
{
    plotXAxisWidth = newRange.size(); //将新的 X 轴范围的大小存储到 plotXAxisWidth 变量中
}

// 图例操作: 双击隐藏/显示曲线
void wavepage::onQCPLegendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item, QMouseEvent* event)
{
    Q_UNUSED(legend) // 不使用参数 legend
    if((event->button() & Qt::LeftButton) == 0) // 如果双击事件不是左键，则返回
        return;
    if(item == nullptr)  // 如果没有点击具体图例项（例如点击了图例边框），则返回
        return;

    // 显示/隐藏某个曲线
    QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem*>(item); //强制转化为 QCPPlottableLegendItem 类型
    QCPAbstractPlottable* pl = plItem->plottable(); //获取 QCPPlottable 类型的对象
    if(pl->visible()) //如果曲线原本可见，执行下列操作
    {
        pl->setName("*" + pl->name()); //将曲线名字前加上 "*" 号
        pl->setVisible(false); //将曲线设置为不可见
    }
    else //如果曲线原本不可见，执行下列操作
    {
        QString oldName = pl->name(); //获取曲线原本的名字
        if(oldName[0] == '*') //如果原本名字的第一个字符为 "*" 号，执行下列操作
            pl->setName(oldName.right(oldName.size() - 1)); //去掉首位的 "*" 号
        pl->setVisible(true); //将曲线设置为可见
    }
    ui->qcpWidget->replot(QCustomPlot::rpQueuedReplot); // 重绘图像 //重新绘制图形
}

// 图例操作: 右键打开图例设置菜单
void wavepage::onQCPLegendClick(QCPLegend *legend, QCPAbstractLegendItem *item, QMouseEvent* event)
{
    // 通过右键点击（或在 Android 上长按）曲线的图例项来重命名曲线
    Q_UNUSED(legend) // 不使用参数 legend
    if((event->button() & Qt::RightButton) == 0) // 如果不是右键单击，则返回
        return;
    if(item == nullptr) // 如果没有点击具体图例项（例如点击了图例边框），则返回
        return;
    setGraphProperty(item); //调用setGraphProperty函数
}

// 图例操作: 弹出图例设置菜单，设置曲线属性
void wavepage::setGraphProperty(QCPAbstractLegendItem *item)
{
    QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem*>(item); //将 QCPAbstractLegendItem 类型的对象强制转化为 QCPPlottableLegendItem 类型
    QCPAbstractPlottable* pl = plItem->plottable(); //获取 QCPPlottable 类型的对象
    QString oldName = pl->name(); //获取曲线原本的名字
    oldName = (!pl->visible() && oldName[0] == '*') ? oldName.right(oldName.size() - 1) : oldName; //如果曲线原本不可见并且名字前面有 "*" 号，则将 "*" 号去掉
    LegendItemDialog dialog(oldName, pl->pen().color()); //创建一个对话框，用于让用户设置曲线的属性，例如名字和颜色
    if(dialog.exec() == QDialog::Accepted) //如果用户点击了“确定”按钮
    {
        pl->setName((pl->visible() ? "" : "*") + dialog.getName()); //根据用户输入修改曲线名字
        pl->setPen(dialog.getColor()); //根据用户输入修改曲线颜色
        ui->qcpWidget->replot(QCustomPlot::rpQueuedReplot); // 重绘图像 //重新绘制图形
    }
}

// 更新跟踪器
void wavepage::updateTracer(double x)
{
    if(plotTracer == nullptr || plotText == nullptr)
        return;
    plotTracer->setGraphKey(x);     // 设置跟踪器X轴坐标
    plotTracer->updatePosition();   // 更新跟踪器位置

    double xValue = plotTracer->position->key();    // 获取跟踪器X轴坐标
    double yValue = plotTracer->position->value();  // 获取跟踪器Y轴坐标
    
    plotText->setText((" " + plotSelectedName + " (%2, %3) ").arg(xValue).arg(yValue)); // 设置跟踪器文本
    ui->qcpWidget->replot(QCustomPlot::rpQueuedReplot); // 重绘图像
}

// 根据鼠标位置更新跟踪器
void wavepage::onQCPMouseMoved(QMouseEvent *event)
{
    double x = ui->qcpWidget->xAxis->pixelToCoord(event->pos().x());    // 获取鼠标位置对应的X轴坐标
    // // 获取鼠标位置对应的坐标 总宽度为1 总高度为1
    // double S_x = event->pos().x() / double(ui->qcpWidget->width());
    // double S_y = event->pos().y() / double(ui->qcpWidget->height());
    // // qDebug() << "S_x:" << S_x << "S_y:" << S_y;
    // // 设置跟踪器文本位置
    // plotText->position->setCoords(S_x+0.05, S_y);  // 设置文本位置坐标
    // 设置颜色为选择的曲线颜色
    plotText->setPen(QPen(ui->qcpWidget->graph(plotSelectedId-1)->pen().color()));  // 设置文本画笔颜色
    updateTracer(x);    // 更新跟踪器
}

// 光标开关
void wavepage::Tracer_Switch(bool ON)
{
    if(plotTracer == nullptr || plotText == nullptr)
        return;
    if(ON)
    {
        connect(ui->qcpWidget, &QCustomPlot::mouseMove, this, &wavepage::onQCPMouseMoved);
        plotTracer->setVisible(true);
        plotText->setVisible(true);
    }else{
        disconnect(ui->qcpWidget, &QCustomPlot::mouseMove, this, &wavepage::onQCPMouseMoved);
        plotTracer->setVisible(false);
        plotText->setVisible(false);
    }
    ui->qcpWidget->replot(QCustomPlot::rpQueuedReplot); // 重绘图像
}



// 绘图开关按钮槽函数
void wavepage::on_Serial_Wave_ON_clicked()
{
    if(parentWidget->Get_Button_Switch(ui->Serial_Wave_ON) == true)
    {
        parentWidget->Button_Switch(ui->Serial_Wave_ON, false);

        if(parentWidget->nowPort == "Serial")
        {
            // 解绑槽newData
            disconnect(serialPort, &SerialPort::dataRead, this, &wavepage::newData);
        }
        // else if(parentWidget->nowPort == "BLE")
        // {
        //     parentWidget->m_ble->ble_stopNotify();
        //     // 解绑槽newData
        //     disconnect(parentWidget->m_ble, &BLE::signal_notifyFinished, this, &wavepage::newData);
        // }
        // 取消所有曲线的选中状态
        // onQCPSelectionClear();
        // 禁用所有曲线选中
        // ui->qcpWidget->setSelectionRectMode(QCP::srmNone);
    }else
    {
        parentWidget->Button_Switch(ui->Serial_Wave_ON, true);
        if(parentWidget->nowPort == "Serial")
        {
            // 将槽newData绑定到信号dataRead
            connect(serialPort, &SerialPort::dataRead, this, &wavepage::newData);
        }
        // else if(parentWidget->nowPort == "BLE")
        // {
        //     parentWidget->m_ble->ble_notify();
        //     // 将槽newData绑定到信号Serial_Read_Data
        //     connect(parentWidget->m_ble, &BLE::signal_notifyFinished, this, &wavepage::newData);
        // }
        // 取消所有曲线的选中状态
        // onQCPSelectionClear();
        // 启用所有曲线选中
        // ui->qcpWidget->setSelectionRectMode(QCP::srmSelect);
    }
}

// 清空绘图数据
void wavepage::on_Serial_Wave_Clean_clicked()
{
    plotCounter = 0;    // 绘图计数器初始化为0
    // label_Data设置为空
    ui->label_Data->setText("");
    // X轴时间戳设置为空
    plotTime = QTime();
    // 移除所有曲线
    ui->qcpWidget->clearGraphs();
    // 清空recordMap
    recordMap.clear();
    // 清空plotMap
    plotMap.clear();
    // 取消所有曲线的选中状态
    onQCPSelectionClear();
    // 重绘绘图窗口
    ui->qcpWidget->replot(QCustomPlot::rpQueuedReplot); // 重绘图像
}

// 跟随最新数据模式
void wavepage::on_Serial_Wave_New_clicked()
{
    if(parentWidget->Get_Button_Switch(ui->Serial_Wave_New) == false)
    {
        parentWidget->Button_Switch(ui->Serial_Wave_New, true);    // 开
        onQCPSelectionClear();  // 取消所有曲线的选中状态
    }else{
        parentWidget->Button_Switch(ui->Serial_Wave_New, false);   // 关
    }
}

// 点显示开关按钮槽函数
void wavepage::on_Serial_Wave_Dot_clicked()
{
    if(parentWidget->Get_Button_Switch(ui->Serial_Wave_Dot) == false)
    {
        parentWidget->Button_Switch(ui->Serial_Wave_Dot, true);    // 开
        for(int i = 0; i < ui->qcpWidget->graphCount(); i++)
            ui->qcpWidget->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle));
    }else{
        parentWidget->Button_Switch(ui->Serial_Wave_Dot, false);   // 关
        for(int i = 0; i < ui->qcpWidget->graphCount(); i++)
            ui->qcpWidget->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone));
    }
    ui->qcpWidget->replot(QCustomPlot::rpQueuedReplot); // 重绘图像
}

// X轴计数模式选择槽函数
void wavepage::on_Serial_Wave_XMode_activated(int index)
{
    if(index == 1)  // 时间模式
    {
        ui->qcpWidget->xAxis->setTicker(plotTimeTicker); // 设置X轴刻度为时间刻度
    }else{      // 默认模式
        ui->qcpWidget->xAxis->setTicker(plotDefaultTicker); // 设置X轴刻度为默认刻度
    }
    // 清空绘图数据
    on_Serial_Wave_Clean_clicked();
}

// 自动缩放
void wavepage::on_Serial_Wave_ZoomAuto_clicked()
{
    ui->qcpWidget->rescaleAxes(true);  //自动缩放
    ui->qcpWidget->yAxis->scaleRange(1.2, ui->qcpWidget->yAxis->range().center());  //Y轴缩放
    ui->qcpWidget->replot(QCustomPlot::rpQueuedReplot); // 重绘图像       //重绘
}

// X轴缩放/Y轴缩放切换
void wavepage::on_Serial_Wave_Zoom_clicked()
{
    if(ui->Serial_Wave_Zoom->text() == tr("X轴缩放"))
    {
        ui->Serial_Wave_Zoom->setText(tr("Y轴缩放"));
        ui->qcpWidget->axisRect()->setRangeZoom(Qt::Vertical);  //设置Y轴缩放
    }else{
        ui->Serial_Wave_Zoom->setText(tr("X轴缩放"));
        ui->qcpWidget->axisRect()->setRangeZoom(Qt::Horizontal);    //设置X轴缩放
    }
}

// 将字符串转换为 double 类型
inline double wavepage::toDouble(const QString& str)
{
    // 根据正则表达式匹配字符串，返回匹配到的第一个字符串，并转换为 double 类型
    return doubleRegex->match(str).captured().toDouble();
}

// 追加数据
void wavepage::newData(const QByteArray& data)
{
    if(plotBuf == nullptr)
        return;
    plotBuf->append(data);
}


// 以下为数据解析 数据格式为: {key1=value1,key2=value2,...}{key1=value1,key2=value2,...}...
// 添加曲线或更新曲线
const int maxDataPoints = 24*60*60; // 最大数据点数

inline void wavepage::Update_Graph(double currKey)
{
    QString Display_Data = "["+QString::number(plotCounter)+"]";
    // 1. 遍历plotMap,更新曲线
    foreach(QString key, plotMap.keys())
    {
        int graphIndex = plotMap[key];       // 获取曲线索引
        QCPGraph *graph = ui->qcpWidget->graph(graphIndex);  // 获取曲线
        // 判断数据量是否大于最大数据点数
        if(graph->data()->size() >= maxDataPoints)
        {
            // 获取最早的数据点的key
            auto it = graph->data()->constBegin();
            if (it != graph->data()->constEnd()) 
            {
                double oldestKey = it->key;
                graph->data()->remove(oldestKey);
            }
        }
        // 添加数据
        graph->addData(currKey, recordMap[key]);



        // 3.显示原始数据
        Display_Data += " " + key + ":" + QString::number(recordMap[key]);
    }
    ui->label_Data->setText(Display_Data);
}

QColor wavepage::Get_Color(QString str)
{
    QColor color;
    // 1.计算字符串的24位哈希值
    quint32 p = 31; //哈希系数，31是一个质数，可以减少哈希冲突
    quint32 m = (1 << 16) - 1; //哈希表长度，这里取2^24-1，即24位哈希值
    quint32 h = 0;
    QChar c;
    for (int i = 0; i < str.length(); i++)
    {
        c = str.at(i);
        h = (h * p + c.unicode()) % m;
    }
    // qDebug() << "h:" << h;

    // 2.以哈希值为种子，生成3个随机数，分别作为RGB值
    QRandomGenerator generator(h);
    int r = generator.bounded(256);
    int g = generator.bounded(256);
    int b = generator.bounded(256);

    // 3. 若r,g,b值都大于150，则最大的颜色值减100
    if (r > 150 && g > 150 && b > 150)
    {
        int max = qMax(qMax(r, g), b);
        if (max == r)
        {
            r -= 100;
        }
        else if (max == g)
        {
            g -= 100;
        }
        else
        {
            b -= 100;
        }
    }

    // qDebug() << "r:" << r << "g:" << g << "b:" << b;
    color = QColor(r, g, b);
    return color;
}

// 根据{}提取第一帧数据
QString wavepage::Get_First_Frame(QString *plotBuf)
{
    // 查找第一个{
    int iStart = plotBuf->indexOf("{");
    // 查找第一个}
    int iEnd = plotBuf->indexOf("}");
    // 如果找不到界限符，就退出
    if (iStart == -1 || iEnd == -1) return "";
    // 提取{}中的数据 不包括界限符
    QString plotData = plotBuf->mid(iStart + 1, iEnd - iStart - 1);
    // 删除已经解析过的数据
    plotBuf->remove(0, iEnd + 1);
    return plotData;
}

// 循环解析数据 输入: QString 
void wavepage::Loop_Parsing_Data(QString *plotBuf)
{
    bool hasData = false;   // 是否解析出数据
    double currKey = 0;     // 当前 X 坐标
    QString plotData;
    if(plotBuf == nullptr || plotBuf->isEmpty()) return;

    while(true)
    {
        // 1.提取第一帧数据
        plotData = Get_First_Frame(plotBuf);
        if (plotData.isEmpty()) break;  // 如果没有解析出数据，退出循环
        hasData = true; // 解析出一帧数据
        plotCounter++;  // 更新绘图计数器
        // 2.提取第一帧数据中的key和value到recordMap
        QStringList items = plotData.split(",");
        foreach(QString itemStr, items)
        {
            QStringList item = itemStr.split("=");  // 以等号分割
            // 增加边界检查
            if(item.size() == 2)
                recordMap.insert(item[0], item[1].toDouble());
        }
        
        // 3. 判断recordMap的数据量是否等于曲线数 是否需要添加新曲线
        if(recordMap.size() != plotMap.size())
        {
            // 1. 遍历recordMap和plotMap,对比键，如果recordMap中有plotMap中没有的键，添加新曲线，并更新对应的plotMap值为曲线id
            foreach(QString key, recordMap.keys())
            {
                // 如果plotMap中没有recordMap中的键，添加新曲线
                if(!plotMap.contains(key))
                {
                    // 添加新曲线
                    QCPGraph* currGraph = ui->qcpWidget->addGraph(); //添加新曲线
                    currGraph->setPen(Get_Color(key)); //设置曲线颜色
                    currGraph->setSelectable(QCP::stSingleData); //设置曲线不可选中
                    // 更新点显示效果

                    if (parentWidget->Get_Button_Switch(ui->Serial_Wave_Dot))   // 若点显示开关打开
                    {
                        currGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle));  // 设置点显示样式为圆形
                    }
                    else
                    {
                        currGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssNone));   // 设置点显示样式为无
                    }   
                    plotMap.insert(key, ui->qcpWidget->graphCount()-1); // 更新plotMap
                    currGraph->setName(key);    // 设置曲线名字
                }
            }
            // 2. 遍历plotMap,对比键，如果plotMap中有recordMap中没有的键，删除曲线和plotMap中的键值对
            foreach(QString key, plotMap.keys())
            {
                // 如果recordMap中没有plotMap中的键，删除曲线和plotMap中的键值对
                if(!recordMap.contains(key))
                {
                    // 删除曲线
                    ui->qcpWidget->removeGraph(plotMap[key]);
                    // 删除plotMap中的键值对
                    plotMap.remove(key);
                }
            }
        }
        // 4. 判断X轴计数模式
        if(ui->Serial_Wave_XMode->currentIndex() == 0) // 自增长 X 坐标
        {
            // 当前 X 坐标为绘图计数器
            currKey = plotCounter;
        }
        else if(ui->Serial_Wave_XMode->currentIndex() == 1) // 时间戳作为 X 坐标
        {
            // 3.若plotTime为空，初始化plotTime为当前时间(首个数据帧的时间戳)
            if(plotTime.isNull())
            {
                // 如果为空，初始化plotTime为当前时间
                plotTime = QTime::currentTime();
            }
            // 当前 X 坐标为时间戳
            currKey = plotTime.msecsTo(QTime::currentTime()) / 1000.0;
        }
        // 更新曲线
        Update_Graph(currKey);
        QApplication::processEvents(); // 处理界面事件，以保证及时响应用户操作
    }
    // 如果没有解析出任何数据，直接返回
    if(!hasData) return;
    if(parentWidget->Get_Button_Switch(ui->Serial_Wave_New) == true)//  如果选择了最新数据模式，更新坐标轴范围和 tracer
    {
        currKey = currKey + plotXAxisWidth / 10.0; // 更新 X 轴坐标
        ui->qcpWidget->xAxis->blockSignals(true);   // 阻塞 X 轴信号
        // 设置 X 轴范围 以当前 X 轴坐标为起始，右对齐。X 轴宽度为 plotXAxisWidth
        ui->qcpWidget->xAxis->setRange(currKey, plotXAxisWidth, Qt::AlignRight);
        ui->qcpWidget->xAxis->blockSignals(false);  // 解除阻塞 X 轴信号
    }
    ui->qcpWidget->replot(QCustomPlot::rpQueuedReplot); // 重绘图像
}

// 绘图
void wavepage::processData()
{
    if(plotBuf->isEmpty())  // 如果 plotBuf 为空，直接返回
        return;
    Loop_Parsing_Data(plotBuf);
}

// 波形测试
void wavepage::on_pushButton_clicked()
{
    if(parentWidget->Get_Button_Switch(ui->pushButton) == true)
    {
        parentWidget->Button_Switch(ui->pushButton, false);
        // 解绑定时器的信号处理函数
        disconnect(TestTimer, &QTimer::timeout, this, &wavepage::on_pushButton_timeout);
        // 解绑Push_Send信号到Serial_Send_Data
        disconnect(this, &wavepage::Push_Send_Data, serialPort, &SerialPort::Serial_Send_Data);
        // 停止定时器
        TestTimer->stop();
        // 删除定时器
        delete TestTimer;
    }else
    {
        TestTimer = new QTimer();
        parentWidget->Button_Switch(ui->pushButton, true);
        // 设置定时器的时间间隔，单位毫秒
        TestTimer->setInterval(10);
        // 绑定定时器的信号处理函数
        connect(TestTimer, &QTimer::timeout, this, &wavepage::on_pushButton_timeout);
        // 绑定Push_Send信号到Serial_Send_Data
        connect(this, &wavepage::Push_Send_Data, serialPort, &SerialPort::Serial_Send_Data);
        // 启动定时器
        TestTimer->start();
    }
}

// 波形测试定时器
void wavepage::on_pushButton_timeout()
{
    // 以曲线格式生成随机数据
    // QString data = QString("%4,E=%5}{A=%1,B=%2,C=%3,D=")
        // .arg(qrand()%100).arg(qrand()%100).arg(qrand()%100).arg(qrand()%100).arg(qrand()%100);
    static int i = 0;
    i++;
    // 生成正弦波曲线
    QString data = QString("{A=%1,B=%2,C=%3,D=%4,E=%5,F=%6,G=%7,H=%8,I=%9,J=%10}")
        .arg(100*sin(2*3.14*0.01*i))
        .arg(100*sin(2*3.14*0.01*i)+10)
        .arg(100*sin(2*3.14*0.01*i)+20)
        .arg(100*sin(2*3.14*0.01*i)+30)
        .arg(100*sin(2*3.14*0.01*i)+40)
        .arg(100*sin(2*3.14*0.01*i)+50)
        .arg(100*sin(2*3.14*0.01*i)+60)
        .arg(100*sin(2*3.14*0.01*i)+70)
        .arg(100*sin(2*3.14*0.01*i)+80)
        .arg(100*sin(2*3.14*0.01*i)+90);


        
    emit Push_Send_Data(data.toUtf8());

    // // 将QString转换为QByteArray
    // QByteArray byteArray = data.toUtf8();

    // // 遍历QByteArray并逐个字节发送
    // for(int i = 0; i < byteArray.size(); ++i) {
    //     QByteArray byteToSend;
    //     byteToSend.append(byteArray[i]);
    //     emit Push_Send_Data(byteToSend);
    // }
}

void wavepage::on_Serial_Help_clicked()
{
    // 弹出提示框
    QString message = QStringLiteral("<font color = black>%1</font>").arg("1. 曲线解码格式为:<br>{key1=value1,key2=value2,...}{key1=value1,key2=value2,...}...<br>");
    message += QStringLiteral("<font color = black>%1</font>").arg("2. 图例操作:<br>双击图例项隐藏/显示曲线<br>右键图例项可以修改曲线颜色<br>单击图例项选中曲线<br>");
    message += QStringLiteral("<font color = black>%1</font>").arg("3. 指针功能:<br>在绘图显示关闭或跟随最新数据关闭时可用<br>单击图例选中曲线后,显示对应曲线鼠标位置X,Y坐标<br>");
    message += QStringLiteral("<font color = magenta>%1</font>").arg("4. 注意:<br>曲线解码格式中的value支持整数或小数<br>key与value均不支持中文<br>最大绘图频率100Hz,最大曲线数10条<br>极限情况下软件稳定性较低<br>建议在高频率情况下尽量减少曲线数,缩短报文长度");
    message += QStringLiteral("<font color = magenta>%1</font>").arg("5. 时间模式下,时间点为绘图时间点,所以会和数据接收时间戳有一定的延迟");
    QMessageBox::information(this, "提示", message);

}

// 波形截图保存
void wavepage::on_Wave_Screen_clicked()
{
    // 截取当前绘图窗口 保存为图片 位置:\Serial_Assistant_Cfg\Wave\Screenshot\时间戳.png
    // 1. 获取当前时间戳
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd_hh-mm-ss");
    // 2. 获取当前绘图窗口
    QPixmap pixmap = ui->qcpWidget->grab();
    // 3. 判断是否存在Serial_Assistant_Cfg/Wave_Screenshot/文件夹
    QDir dir(QCoreApplication::applicationDirPath() + "/Serial_Assistant_Cfg/Wave_Screenshot/");
    if(!dir.exists())
    {
        // 3.1 如果不存在,创建文件夹
        dir.mkpath(QCoreApplication::applicationDirPath() + "/Serial_Assistant_Cfg/Wave_Screenshot/");
    }
    // 3. 保存图片
    QString path = QCoreApplication::applicationDirPath() + "/Serial_Assistant_Cfg/Wave_Screenshot/" + current_date + ".png";
    pixmap.save(path, "png");
    // 4. 判断是否保存成功
    if(QFile::exists(path))
    {
        // 4. 弹出提示框 保存成功 时间戳.png
        QString message = QStringLiteral("<font color = black>%1</font>").arg("保存成功 " + current_date + ".png");
        QMessageBox::information(this, "提示", message);  
    }else{
        QMessageBox::information(this, "提示", "截图失败!");
    }
}


// 打开文件夹
void wavepage::on_Wave_Open_clicked()
{
    // 1. 判断是否存在Serial_Assistant_Cfg/Wave_Screenshot文件夹
    QDir dir(QCoreApplication::applicationDirPath() + "/Serial_Assistant_Cfg/Wave_Screenshot/");
    if(!dir.exists())
    {
        // 1.1 如果不存在,创建文件夹
        dir.mkpath(QCoreApplication::applicationDirPath() + "/Serial_Assistant_Cfg/Wave_Screenshot/");
    }
    // 2. 打开文件夹
    QDesktopServices::openUrl(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/Serial_Assistant_Cfg/Wave_Screenshot/"));
}

// 重载键盘按下事件 并触发信号
void wavepage::keyPressEvent(QKeyEvent *event)
{
    emit myKeyPressSignal(event);
}

// 重载键盘释放事件
void wavepage::keyReleaseEvent(QKeyEvent *event)
{
    emit myKeyReleaseSignal(event);
}


