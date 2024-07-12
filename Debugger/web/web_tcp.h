#ifndef WEB_TCP_H
#define WEB_TCP_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>

class web_tcp : public QObject
{
    Q_OBJECT
    public:
        web_tcp(QObject *parent = nullptr);

        // 创建enum类型用来保存当前的模式
        enum Mode
        {
            TCP_NONE,
            TCP_SERVER,
            TCP_CLIENT,
        };
        // 返回当前的模式
        Mode getMode(){
            return tcp_mode;
        }

        // 监听端口
        void tcp_listen(QString ip, quint16 port);
        // 停止监听
        void tcp_stop_listen();
        // 连接服务器
        void tcp_connect(QString ip, quint16 port);
        // 断开连接
        void tcp_disconnect();

    signals:
        // 连接成功
        void tcp_client_connected();
        // 断开连接
        void tcp_client_disconnected();
        // 客户端状态改变
        void tcp_client_status_changed(QAbstractSocket::SocketState state);

        // 客户端接入
        void tcp_server_new_connection();
        // 接收到数据
        void tcp_server_read_data(QByteArray data);
        
        // // 发送计数
        // void tcp_send_count(int count);
        // 接收计数
        void tcp_read_count(int count);

    private slots: 
        void onStateChanged(QAbstractSocket::SocketState state);

    private:
        QThread *web_Thread;                // web端口线程

        QTcpSocket *m_tcpSocket = nullptr;  // 客户端套接字
        QTcpServer *m_tcpServer = nullptr;  // 服务器套接字

        QString m_ip;                       // ip地址
        quint16 m_port;                     // 端口号

        Mode tcp_mode = TCP_NONE;           // 当前模式
};

#endif // WEB_TCP_H
