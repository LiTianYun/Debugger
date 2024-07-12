#ifndef BUTTON_SETTING_H
#define BUTTON_SETTING_H

#include <QDialog>
#include <QColorDialog>

class MyPushButton;

namespace Ui
{
class Button_Setting;
}

class Button_Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Button_Setting(QWidget *parent = nullptr);
    explicit Button_Setting(const QString& name, const QColor& color, const QByteArray &data, const bool &hex, const bool &protect, MyPushButton *button, QWidget *parent = nullptr);
    ~Button_Setting();

    QColor getColor();
    QString getName();
    bool getHex();
    bool getProtect();
    QByteArray getData();
public slots:
    void setName(const QString &name);
    void setColor(const QColor &color);
    void setHex(const bool &hex);
    void setProtect(const bool &protect);
    void setData(const QByteArray &data);
private slots:
    void on_colorButton_clicked();

    void on_nameEdit_editingFinished();
    void on_radioButton_clicked();
    void on_dataEdit_textChanged();
    void on_DeleteButton_clicked();
    void on_checkBox_stateChanged(int arg1);

    void on_SaveButton_clicked();


    void on_CopyButton_clicked();

private:
    Ui::Button_Setting *ui;
    QColorDialog *colorDialog;
    MyPushButton *m_button;

    bool m_hex;
    bool m_protect;
    QColor m_color;
    QString m_name;
    QByteArray m_data;

// 信号
signals:
    void saveButton();
    void CopyButton();

};

#endif // BUTTON_SETTING_H
