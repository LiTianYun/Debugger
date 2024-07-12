#ifndef WAVEPAGE_H
#define WAVEPAGE_H

#include <QWidget>
#include <random>

#include "mycustomplot.h"
#include "serial_port/serialport.h"

class Widget;

namespace Ui {
class wavepage;
}

class wavepage : public QWidget
{
    Q_OBJECT

public:
    explicit wavepage(Widget *parent = nullptr, SerialPort *Port = nullptr);
    ~wavepage();

    void Init_wavepage();                   // 波形页面 初始化函数
    void newData(const QByteArray& data);   // 波形页面 追加新数据

private slots:
    void processData();   // 数据解析函数
    void onQCPSelectionChanged();               // 同步图例的选中和曲线的选中
    void onXAxisChangedByUser(const QCPRange &newRange);    // 存储X轴范围大小
    void onQCPLegendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item, QMouseEvent* event);  // 图例操作: 双击隐藏/显示曲线
    void onQCPLegendClick(QCPLegend *legend, QCPAbstractLegendItem *item, QMouseEvent* event);        // 图例操作: 右键打开图例设置菜单
    void onQCPMouseMoved(QMouseEvent *event);       // 根据鼠标位置更新跟踪器

    void on_Serial_Wave_ON_clicked();           // 绘图开关按钮
    void on_Serial_Wave_Clean_clicked();        // 清空按钮
    void on_Serial_Wave_Dot_clicked();              // 点显示开关按钮
    void on_Serial_Wave_XMode_activated(int index); // X轴计数模式选择槽函数
    void on_Serial_Wave_New_clicked();        // 跟随最新数据按钮
    void on_Serial_Wave_Zoom_clicked();             // X/Y缩放按钮
    void on_Serial_Wave_ZoomAuto_clicked();         // 自动缩放按钮
    void on_pushButton_clicked();                  // 测试按钮
    void on_Serial_Help_clicked();      // 帮助按钮
    void on_Wave_Screen_clicked();          // 截图按钮
    void on_Wave_Open_clicked();        // 打开按钮
    
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
signals:
    void myKeyPressSignal(QKeyEvent *event);// 键盘按下信号
    void myKeyReleaseSignal(QKeyEvent *event);// 键盘释放信号

    void Push_Send_Data(QByteArray data);        // 发送数据信号

private:
    Ui::wavepage *ui;
    Widget *parentWidget;                        //父窗口指针
    SerialPort *serialPort;                     //串口端口指针

    QString* plotBuf;                           // 绘图缓存 
    QCPItemTracer* plotTracer;                  // 绘图追踪器
    QCPItemText* plotText;                      // 绘图文本
    QSharedPointer<QCPAxisTicker> plotDefaultTicker;    // 绘图默认刻度
    QTime plotTime;                             // 绘图时间
    qint64 plotCounter;                         // 绘图计数器
    double plotXAxisWidth;                      // 绘图X轴宽度
    QSharedPointer<QCPAxisTickerTime> plotTimeTicker = QSharedPointer<QCPAxisTickerTime>(new QCPAxisTickerTime);    // 绘图时间刻度
    QTimer* m_dataProcessTimer;                 // 数据处理定时器
    

    int plotSelectedId = 0;                     // 追踪器选中的曲线ID 0:无选中 
    QString plotSelectedName;                   // 追踪器选中的曲线名称

    QRegularExpression* doubleRegex;            // 正则表达式 限制输入为整数或小数

    QString plotFrameSeparator = "\n";                 // 帧分隔符
    QString plotDataSeparator = ",";                  // 项分隔符
    QString plotClearFlag = "CFG";                      // 清空符
    quint8 plotGraphNum = 0;                    // 曲线数量
    QMap<QString, double>& recordMap;           // 曲线数据表
    QMap<QString, int>& plotMap;                 // 曲线id表

    void Tracer_Switch(bool ON);                // 光标开关        
    void Update_Graph(double currKey);                        // 更新曲线
    QColor Get_Color(QString str);              // 计算曲线颜色
    
    void onQCPSelectionClear();                 // 清除所有曲线的选中状态
    
    void setGraphProperty(QCPAbstractLegendItem *item);    // 图例操作: 弹出图例设置菜单，设置曲线属性
    void updateTracer(double x);                    // 更新追踪器
    inline double toDouble(const QString& str);     // 根据正则表达式 字符串转double

    QString Get_First_Frame(QString *plotBuf);       // 获取第一帧数据
    void Loop_Parsing_Data(QString *plotBuf);        // 循环解析数据


    QTimer *TestTimer;                              // 测试定时器
    void on_pushButton_timeout();                   // 测试定时器槽函数
};




#endif // WAVEPAGE_H
