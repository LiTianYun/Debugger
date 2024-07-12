#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include "qevent.h"
#include "serial_port/serialport.h"
#include "buttons/button_setting.h"
#include "widget.h"

class Widget;

namespace Ui {
class Buttons;
}

class Buttons : public QWidget
{
    Q_OBJECT

public:
    Widget *parentWidget;                       //父窗口指针
    SerialPort *serialPort;                     //串口端口指针

    explicit Buttons(Widget *parent = nullptr, SerialPort *Port = nullptr);
    ~Buttons();

    MyPushButton *CreateButton();                // 新建按钮并绑定信号

private:
    Ui::Buttons *ui;

    QSettings  *settings;                    // 保存配置文件
    
    QString NowPath;                        // 当前路径

    // 跟随鼠标移动的按钮
    MyPushButton *MouseFollowButton = nullptr;
    
    void Load_clicked(QString fileName);
private slots:
    void on_Button_add_clicked();
    void on_Button_auto_clicked();
    void on_Button_Load_clicked();
    void on_Button_save_clicked();
    void on_Button_save_as_clicked();
    void on_Button_clear_clicked();

    void mousePosChanged(QPoint pos);
    void rightLongClicked(MyPushButton *button);
    void rightLongClickedRelease(MyPushButton *button);





signals:
    void Send_Data(QByteArray data);        // 发送数据信号

};


// 重写按键相应类 用来区分左右按键
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QWidget *parent, Buttons *PBu, SerialPort *Port):QPushButton(parent) {
        serialPort = Port;
        // 按钮的名字默认为NewButton
        setText("NewButton");
        // 颜色默认为浅灰色
        setButtonColor(QColor(0, 0, 0));
        // 按钮样式
        setFixedSize(sizeHint());
        setFixedHeight(height()*2);
        // StatusColor默认为橙色
        setStatusColor(QColor(255, 165, 0));
        // 获取父窗口指针
        ParentButtons = PBu;
        Widget *Widget = PBu->parentWidget;

        // connect(this, &MyPushButton::SendData, serialPort, &SerialPort::Serial_Send_Data);
        connect(this, &MyPushButton::SendData, Widget, &Widget::Send_Data_Slot);
    }
    ~MyPushButton() {}

    // 保存按钮坐标
    void SaveButtonPos(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    // 获取保存的按钮坐标
    void GetButtonPos(int &x, int &y)
    {
        x = m_x;
        y = m_y;
    }

    // 设置按钮id
    void SetButtonID(int id)
    {
        m_id = id;
    }

    // 获取按钮id
    int GetButtonID()
    {
        return m_id;
    }

    // 设置保护
    void setProtect(bool protect)
    {
        m_protect = protect;
    }

    // 保存按钮为json格式
    QJsonObject SaveButtonToJson()
    {
        QJsonObject json;
        json.insert("ID", m_id);
        json.insert("Name", text());
        json.insert("Color", m_color.name());
        json.insert("Data", QString(m_data.toHex()));
        json.insert("Hex", m_hex);
        json.insert("X", m_x);
        json.insert("Y", m_y);
        json.insert("Protect", m_protect);
        return json;
    }

    // 将json格式转换为按钮
    void LoadButtonFromJson(QJsonObject json)
    {
        setID(json.value("ID").toInt());
        setText(json.value("Name").toString());
        setButtonColor(QColor(json.value("Color").toString()));
        setButtonData(QByteArray::fromHex(json.value("Data").toString().toUtf8()));
        setButtonHex(json.value("Hex").toBool());
        SaveButtonPos(json.value("X").toInt(), json.value("Y").toInt());
        setProtect(json.value("Protect").toBool());

        // 根据名称重新设置按钮大小
        setFixedSize(sizeHint());
        setFixedHeight(height()*2);
    }

private:
    SerialPort *serialPort;                     //串口端口指针
    int m_id = 0;   // 按钮id
    QTimer *rightButtonTimer;
    Buttons *ParentButtons;                        //父窗口指针
    // 按钮字体颜色
    QColor m_color;
    // 按钮状态颜色
    QColor StatusColor;
    // 点击按钮发送的数据
    QByteArray m_data;
    // 数据hex使能
    bool m_hex = true;     // true则发送hex数据 false则发送ascii数据
    // 按钮保护使能
    bool m_protect = false;

    // 按钮坐标
    int m_x;
    int m_y;

    // 设置id
    void setID(int id)
    {
        m_id = id;
    }
    

    // 设置按钮背景颜色
    void setButtonColor(QColor color)
    {
        // 设置按钮字体颜色
        m_color = color;
        setStyleSheet(QString("color: %1").arg(m_color.name()));
        // 字体加粗
        setFont(QFont("Microsoft YaHei", 9, QFont::Bold));
    }

    // 设置按钮状态颜色
    void setStatusColor(QColor color)
    {
        StatusColor = color;
    }
    
    // 设置按钮发送的数据
    void setButtonData(QByteArray data)
    {
        m_data = data;
    }

    void setButtonHex(bool hex)
    {
        m_hex = hex;
    }

    void DeleteTimer()
    {
        if(rightButtonTimer)
        {
            rightButtonTimer->stop();
            delete rightButtonTimer;
            rightButtonTimer = nullptr;
        }
    }

private slots:

    // 重写paintEvent函数 在按钮右上角添加一个小圆点用来显示按钮状态 
    void paintEvent(QPaintEvent *event) override
    {
        // 首先调用基类的paintEvent函数，以便它可以绘制按钮的正常外观
        QPushButton::paintEvent(event);

        // 在按钮右上角添加一个小圆点用来显示按钮状态
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(StatusColor));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(width()-10, 5, 5, 5);

        // 左上角显示按钮id
        painter.setPen(QColor(26, 188, 156));
        painter.setFont(QFont("Microsoft YaHei", 6));
        painter.drawText(5, 10, QString::number(m_id));

        // 若按钮保护则在右下角显示锁
        if(m_protect)
        {
            painter.setPen(QColor(255, 0, 0));
            painter.setFont(QFont("Microsoft YaHei", 6));
            painter.drawText(width()-20, height()-5, "lock");
        }else
        {
            // 删除左下角锁
            painter.setPen(QColor(255, 255, 255));
            painter.setFont(QFont("Microsoft YaHei", 6));
            painter.drawText(width()-20, height()-5, " ");
        }
    }

    void rightButtonLongPressed()   // 右键长按槽函数
    {
        DeleteTimer();
        emit rightLongClicked(this);
        qDebug() << "Right Button Long Pressed!";

        // 长按则按钮下增加阴影 浅灰色 四周偏移
        QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect();
        shadow_effect->setOffset(0);
        shadow_effect->setColor(QColor(0, 0, 0, 100));
        shadow_effect->setBlurRadius(20);
        setGraphicsEffect(shadow_effect);

    }
    
    void mousePressEvent(QMouseEvent *event)    // 鼠标按下事件
    {
        if(event->button() == Qt::LeftButton)
        {
            if(m_protect) return;   // 按钮保护则不响应
            // 状态绿色
            setStatusColor(QColor(0, 255, 0));
        }
        else if(event->button() == Qt::RightButton)
        {
            // 状态灰色
            setStatusColor(QColor(128, 128, 128));

            rightButtonTimer = new QTimer(this);
            connect(rightButtonTimer, &QTimer::timeout, this, &MyPushButton::rightButtonLongPressed);
            rightButtonTimer->start(200); // 触发长按信号
        }
        QPushButton::mousePressEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent *event)  // 鼠标释放事件
    {
        // 左键释放 串口发送数据
        if(event->button() == Qt::LeftButton)
        {
            if(m_protect) return;   // 按钮保护则不响应
            // StatusColor默认为橙色
            setStatusColor(QColor(255, 165, 0));
            // qDebug() << "Left Button Clicked! : " << m_data.toHex();
            // 若m_data不为空则发送
            if(!m_data.isEmpty())
            {
                emit SendData(m_data);
            }

            emit leftClicked(this);
        }
        else if(event->button() == Qt::RightButton)     
        {
            // StatusColor默认为橙色
            setStatusColor(QColor(255, 165, 0));

            // 右键短按释放 打开设置界面
            if(rightButtonTimer && rightButtonTimer->isActive())    
            {
                // 如果定时器还在运行，说明没有长按，只是普通的点击
                DeleteTimer();
                emit rightClicked(this);
                // 弹出Button_Setting界面并等待关闭
                Button_Setting *button_setting = new Button_Setting(this->text(), m_color, m_data, m_hex, m_protect, this);
                // 连接保存按钮信号
                connect(button_setting, &Button_Setting::saveButton, this, [=](){
                    // 更新名字、数据、颜色
                    setText(button_setting->getName());
                    setButtonColor(button_setting->getColor());
                    setButtonData(button_setting->getData());
                    setButtonHex(button_setting->getHex());
                    setProtect(button_setting->getProtect());
                    // 按钮样式
                    setFixedSize(sizeHint());   // 根据名字长度设置按钮大小
                    setFixedHeight(height()*2);
                });
                // 连接复制按钮信号
                connect(button_setting, &Button_Setting::CopyButton, this, [=](){
                    // 在父窗口中新建一个按钮
                    if (ParentButtons != nullptr) {
                        MyPushButton *button = ParentButtons->CreateButton();
                        // 设置按钮名字、数据、颜色
                        button->setText(button_setting->getName());
                        button->setButtonColor(button_setting->getColor());
                        button->setButtonData(button_setting->getData());
                        button->setButtonHex(button_setting->getHex()); 
                        button->setProtect(button_setting->getProtect());
                        // 按钮样式
                        button->setFixedSize(button->sizeHint());
                        button->setFixedHeight(button->height()*2);
                    }else{
                        // 弹出提示框
                        QMessageBox::warning(this, "Warning", "未知错误！");
                    }
                    
                });

                button_setting->exec(); // 等待关闭
            }
            else    // 右键长按释放
            {
                // 取消按钮坐标跟随鼠标
                emit rightLongClickedRelease(this);
                // 恢复按钮下阴影
                setGraphicsEffect(nullptr);
            }
        }

        // 调用父类的 mousePressEvent，以便正常处理点击事件
        QPushButton::mouseReleaseEvent(event);
    }
    

        
signals:
    void leftClicked(MyPushButton *button);
    void rightClicked(MyPushButton *button);   // 右键短按信号
    void rightLongClicked(MyPushButton *button);   // 右键长按信号
    void rightLongClickedRelease(MyPushButton *button);   // 右键长按释放信号
    void SendData(QByteArray data);     // 发送数据信号
};







class MyFrame : public QFrame
{
    Q_OBJECT
public:
    explicit MyFrame(QWidget *parent = nullptr) : QFrame(parent) {}

    // 自动排列控件
    void AutoArrangeWidgets()
    {
        // 获取frame的宽度
        int frameWidth = width();
        // 获取frame中所有的子控件
        QList<QWidget *> widgets = findChildren<QWidget *>();
        // 遍历所有子控件 并根据其宽度设置它和它后面的控件的位置
        // 记录上一个控件的尾部位置
        int lastEnd_x = 0;
        int lastEnd_y = 10;
        int max_height = 0;
        for(int i = 0; i < widgets.size(); i++)
        {
            // 获取该控件的宽度
            int width = widgets[i]->width();
            int height = widgets[i]->height();
            // 记录每一行的最大高度
            if(height > max_height) max_height = height;
            // 计算该控件的尾部位置 若超出frame宽度则换行
            int end = lastEnd_x + width + 10;
            if(end > frameWidth)
            {
                lastEnd_x = 0;
                lastEnd_y = lastEnd_y + max_height + 10;
                max_height = 0; // 每一行重新计算最大高度
            }
            // 设置控件位置 x坐标为上一个控件的尾部位置+10 y上一个控件的y坐标
            widgets[i]->move(lastEnd_x + 10, lastEnd_y);
            // 更新上一个控件的尾部位置
            lastEnd_x = lastEnd_x + 10 + width;
        }
    }

    // 增加控件 并自动设置其坐标
    void AddWidget(QWidget *widget)
    {
        widget->setParent(this);
        widget->show();
        widgetNum++;
        widget->move(10, 10);
    }

    // 设置指定控件坐标
    void SetWidgetPos(QWidget *widget, int x, int y)
    {
        widget->move(x, y);
    }

    // 获取当前控件数量
    int GetWidgetNum()
    {
        return widgetNum;
    }


    // 清空所有控件
    void ClearWidgets()
    {
        foreach (QObject *child, children())
        {
            if (child->isWidgetType())
            {
                QWidget *widget = qobject_cast<QWidget *>(child);
                widget->deleteLater();
            }
        }
        widgetNum = 0;
    }

private:
    // 控件数量
    int widgetNum = 0;

protected:

    void paintEvent(QPaintEvent *event) override    // 重写绘图事件 绘制点阵
    {
        // 首先调用基类的paintEvent函数，以便它可以绘制框架的正常外观
        QFrame::paintEvent(event);

        QPainter painter(this);

        // 绘制点阵
        // 灰色 20%透明度
        painter.setPen(QColor(0, 0, 0, 50));
        // 每隔10像素画一个点
        for (int x = 0; x < width(); x += 10)
        {
            for (int y = 0; y < height(); y += 10)
            {
                painter.drawPoint(x, y);
            }
        }
        // 遍历frame中的控件，将其坐标到最近的栅格点(10像素)
        foreach (QObject *child, children())
        {
            if (child->isWidgetType())
            {
                QWidget *widget = qobject_cast<QWidget *>(child);
                // 设置控件宽度和高度为10的倍数 只能扩大不能缩小
                int w = (widget->width() / 10);
                int h = (widget->height() / 10);
                if(widget->width() % 10 != 0) w+=1;
                if(widget->height() % 10 != 0) h+=1;
                widget->setFixedSize(w*10, h*10);

                // 将坐标到最近的栅格点(10像素)
                QPoint pos = widget->pos();
                pos.setX((pos.x() / 10) * 10);
                pos.setY((pos.y() / 10) * 10);
                widget->move(pos);
            }
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override    // 重写鼠标移动事件
    {
        QPoint pos = event->pos();
        // 在这里，你可以使用 pos 变量来获取鼠标的位置
        // 你也可以发出一个信号，将鼠标的位置传递给其他对象
        emit mousePosChanged(pos);
    }

signals:
    void mousePosChanged(QPoint pos);
};


#endif // BUTTONS_H
