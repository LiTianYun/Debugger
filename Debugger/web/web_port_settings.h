#ifndef WEB_PORT_SETTINGS_H
#define WEB_PORT_SETTINGS_H

#include <QDialog>
#include "widget.h"
#include "web_tcp.h"

namespace Ui {
class Web_Port_Settings;
}

class Web_Port_Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Web_Port_Settings(Widget *parent = nullptr, web_tcp *web = nullptr);
    ~Web_Port_Settings();

private slots:
    void tcp_client_connected_slot();
    void tcp_client_disconnected_slot();

    void on_Server_Create_Button_clicked();
    void on_Connect_Server_Button_clicked();

private:
    Ui::Web_Port_Settings *ui;
    Widget *parentWidget;                        // 父窗口
    web_tcp *m_web_tcp;                            // web端口

    void on_Update_Button_clicked();
};

#endif // WEB_PORT_SETTINGS_H
