#include "button_setting.h"
#include "ui_button_setting.h"
#include "buttons.h"

Button_Setting::Button_Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Button_Setting)
{
    ui->setupUi(this);
    colorDialog = new QColorDialog;
    // 设置该窗口为模态窗口 该窗口关闭后才能操作父窗口
    this->setWindowModality(Qt::ApplicationModal);
    // 设置窗口标题
    this->setWindowTitle("按键设置");


    // 隐藏checkBox
    // ui->checkBox->hide();   // 未开发功能
}

Button_Setting::Button_Setting(const QString &name, const QColor &color, const QByteArray &data, const bool &hex, const bool &protect,
    MyPushButton *button, QWidget *parent) : Button_Setting(parent)
{
    m_button = button;
    setName(name);
    setColor(color);
    setHex(hex);
    setData(data);
    setProtect(protect);
}

Button_Setting::~Button_Setting()
{
    delete ui;
}

void Button_Setting::on_colorButton_clicked()
{
    if(colorDialog->exec() != QDialog::Accepted)
        return;
    m_color = colorDialog->currentColor();
    QString qss = QString("background-color: %1").arg(m_color.name());
    ui->colorButton->setStyleSheet(qss);
    colorDialog->setCurrentColor(m_color);
}

void Button_Setting::on_nameEdit_editingFinished()
{
    m_name = ui->nameEdit->text();
}

void Button_Setting::on_radioButton_clicked()
{
    m_hex = ui->radioButton->isChecked();

    // 获取dataEdit中的数据
    QByteArray data = ui->dataEdit->toPlainText().toUtf8();

    // 字符串发送状态
    if(!m_hex)
    {
        // 将数据解析出16进制字符串并转化为Ascii码
        QString textData;
        // 舍弃所有空格
        data = data.replace(" ", "");
        // 两两分割并转换为Ascii码
        for(int i=0; i<data.length(); i+=2)
        {
            QString str = data.mid(i, 2);   // 截取两个字符
            // 判断是否为有效Ascii码 0～127
            if(str.toInt(NULL, 16) > 127) textData += "?";
            else textData += QChar(str.toInt(NULL, 16));
        }
        // 将转换后的数据显示到输入框中
        ui->dataEdit->setText(textData);
        ui->SaveButton->setEnabled(true); // 启用发送按钮
    }
    else    //16进制发送状态
    {
        // 将数据转化为16进制形式
        QString hexData = data.toHex(' ').toUpper();
        // 判断第一个字符是否为空格，若是则删除
        if(hexData.startsWith(' ')) hexData.remove(0, 1);
        // 将转换后的数据显示到输入框中
        ui->dataEdit->setText(hexData);

    }
    on_dataEdit_textChanged();
}

// dataEdit输入框内容改变时触发
void Button_Setting::on_dataEdit_textChanged()
{
    static QString Data_Last; // 保存上一次的内容
    QTextCursor cursor = ui->dataEdit->textCursor(); // 获取光标位置

    if(m_hex)
    {
        // 判断是输入还是删除
        if(ui->dataEdit->toPlainText().length() >= Data_Last.length())
        {
            QString hexData = ui->dataEdit->toPlainText().right(1); // 提取光标前一个字符
            if(hexData.contains(QRegExp("[^0-9a-fA-F]"))) // 包含非数字和字母
            {
                cursor.deletePreviousChar(); // 删除光标前一个字符
            }
            // 判断光标位置为3或者4的倍数时，在光标前插入空格
            if(cursor.position() == 3 || (cursor.position()-3)%3 == 0)
            {
                // 判断光标位置是否为最前面
                if(cursor.position() != 0)
                {
                    QSignalBlocker blocker(ui->dataEdit);    // 阻塞信号
                    //调整光标位置
                    cursor.setPosition(cursor.position() - 1);
                    // 插入空格
                    cursor.insertText(" ");
                    // 调整光标位置
                    cursor.setPosition(cursor.position() + 1);
                }
            }
        }
        QString str = ui->dataEdit->toPlainText().replace(QRegExp("\\s+"), ""); // 去除空格
        if(str.length() % 2 != 0) ui->SaveButton->setEnabled(false); // 若为奇数则禁用发送按钮
        else ui->SaveButton->setEnabled(true); // 否则启用发送按钮
        // 保存当前内容
        Data_Last = ui->dataEdit->toPlainText();
        m_data = QByteArray::fromHex(str.toLatin1().data());
    }else{
        m_data = ui->dataEdit->toPlainText().toLocal8Bit();
    }
}

QColor Button_Setting::getColor()
{
    return m_color;
};

QString Button_Setting::getName()
{
    return m_name;
};

QByteArray Button_Setting::getData()
{
    qDebug() << m_data.toHex();
    return m_data;
};

bool Button_Setting::getHex()
{
    return m_hex;
};

bool Button_Setting::getProtect()
{
    return m_protect;
}

void Button_Setting::setName(const QString& name)
{
    m_name = name;
    ui->nameEdit->setText(m_name);
}

void Button_Setting::setData(const QByteArray& data)
{
    m_data = data;
    if(m_hex)
    {
        QString hexData = m_data.toHex(' ').toUpper();  // 转换为16进制字符串
        if(hexData.startsWith(' ')) hexData.remove(0, 1);   // 删除第一个空格
        ui->dataEdit->setText(hexData); 
    }else{
        QString textData;
        for(int i=0; i<m_data.length(); i++)
        {
            textData += m_data.at(i);
        }
        ui->dataEdit->setText(textData);
    }
}

void Button_Setting::setHex(const bool& hex)
{
    m_hex = hex;
    ui->radioButton->setChecked(m_hex);
}

void Button_Setting::setProtect(const bool& protect)
{
    m_protect = protect;
    ui->checkBox->setChecked(m_protect);
}

void Button_Setting::setColor(const QColor& color)
{
    if(!color.isValid())
        return;
    m_color = color;
    QString qss = QString("background-color: %1").arg(color.name());
    ui->colorButton->setStyleSheet(qss);
    colorDialog->setCustomColor(0, color);
    colorDialog->setCurrentColor(color);
}

void Button_Setting::on_DeleteButton_clicked()
{
    // 删除父按钮
    m_button->deleteLater();
    // 关闭窗口
    close();
}



void Button_Setting::on_SaveButton_clicked()
{
    emit saveButton();
    // 关闭窗口
    close();
}


void Button_Setting::on_checkBox_stateChanged(int arg1)
{
    
    if(arg1 == 0)
    {
        m_protect = false;
        m_button->setProtect(false);
    }
    else
    {
        m_protect = true;
        m_button->setProtect(true);
    }
    
}

// 复制按钮
void Button_Setting::on_CopyButton_clicked()
{
    emit CopyButton();
}

