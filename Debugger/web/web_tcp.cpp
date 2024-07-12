#include "web_tcp.h"
#include <QDebug>


web_tcp::web_tcp(QObject *parent) : QObject(parent)
{
    m_tcpSocket = new QTcpSocket(this);
    m_tcpServer = new QTcpServer(this);

    web_Thread = new QThread(this);  // 多线程对象
    this->moveToThread(web_Thread);     // 将当前对象移动到多线程中
    web_Thread->start();                // 启动多线程

    connect(m_tcpServer,&QTcpServer::newConnection, [=](){
        m_tcpSocket = m_tcpServer->nextPendingConnection();

        connect(m_tcpSocket,&QTcpSocket::connected, [=](){
            qDebug() << "** 客户端连接";
            qDebug() << "** ip: " << m_tcpSocket->peerAddress().toString();
            qDebug() << "** 端口: " << QString::number(m_tcpSocket->peerPort());
        });

        connect(m_tcpSocket,&QTcpSocket::disconnected, [=](){
            qDebug() << "** 客户端断开连接";
            m_tcpSocket->deleteLater();
        });
        connect(m_tcpSocket,&QTcpSocket::stateChanged, this, &web_tcp::onStateChanged);
        connect(m_tcpSocket,&QTcpSocket::readyRead, [=](){
            while(m_tcpSocket->canReadLine())
            {
                QByteArray data = m_tcpSocket->readLine();
                qDebug() << "** 接收到数据：" << data;
            }
        });
        qDebug() << "** 客户端连接";
        qDebug() << "** ip: " << m_tcpSocket->peerAddress().toString();
        qDebug() << "** 端口: " << QString::number(m_tcpSocket->peerPort());
    });
    

    connect(m_tcpSocket, &QTcpSocket::connected, [=](){
        qDebug() << "连接成功";
        emit tcp_client_connected();
    });
    connect(m_tcpSocket, &QTcpSocket::disconnected, [=](){
        qDebug() << "断开连接";
        emit tcp_client_disconnected();
    });
    connect(m_tcpSocket, &QTcpSocket::readyRead, [=]() {
        QByteArray data = m_tcpSocket->readAll();
        // QByteArray data = m_tcpSocket->readLine();
        qDebug() << "接收到数据：" << data;
        emit tcp_server_read_data(data);
        emit tcp_read_count(data.size());
    });
    connect(m_tcpSocket,&QTcpSocket::stateChanged, this, &web_tcp::onStateChanged);
}

void web_tcp::onStateChanged(QAbstractSocket::SocketState state)
{
    qDebug() << "状态改变";
    switch (state) {
    case QAbstractSocket::UnconnectedState:
        qDebug() << "未连接";
        break;
    case QAbstractSocket::HostLookupState:
        qDebug() << "主机查找";
        break;
    case QAbstractSocket::ConnectingState:
        qDebug() << "连接中";
        break;
    case QAbstractSocket::ConnectedState:
        qDebug() << "已连接";
        break;
    case QAbstractSocket::BoundState:
        qDebug() << "绑定";
        break;
    case QAbstractSocket::ClosingState:
        qDebug() << "关闭中";
        break;
    case QAbstractSocket::ListeningState:
        qDebug() << "监听中";
        break;
    default:
        break;
    }
    emit tcp_client_status_changed(state);
}


// 监听端口
void web_tcp::tcp_listen(QString ip, quint16 port)
{
    tcp_disconnect();  // 断开连接
    QHostAddress addr(ip);
    // 监听
    m_tcpServer->listen(addr, port);
    qDebug() << "**开始监听";
    qDebug() << "**服务器地址：" << m_tcpServer->serverAddress().toString();
    qDebug() << "**服务器端口：" << QString::number(m_tcpServer->serverPort());

    // 模式修改
    tcp_mode = TCP_SERVER;
}

// 停止监听
void web_tcp::tcp_stop_listen()
{
    if(m_tcpServer->isListening())
    {
        m_tcpServer->close();
    }
    qDebug() << "**停止监听";

    tcp_mode = TCP_NONE;
}

// 连接服务器
void web_tcp::tcp_connect(QString ip, quint16 port)
{
    tcp_stop_listen();  // 停止监听
    // 连接
    m_tcpSocket->connectToHost(ip, port);
    qDebug() << "**开始连接";

    // 模式修改
    tcp_mode = TCP_CLIENT;
}

// 断开连接
void web_tcp::tcp_disconnect()
{
    if(m_tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        m_tcpSocket->disconnectFromHost();
    }
    qDebug() << "断开连接";

    tcp_mode = TCP_NONE;
}


// web_tcp::web_tcp(QObject *parent) : QObject(parent)
// {

// }

// void web_tcp::onStateChanged(QAbstractSocket::SocketState state)
// {
//     QString str;
//     switch (state) {
//     case QAbstractSocket::UnconnectedState:
//         str = "未连接";
//         break;
//     case QAbstractSocket::HostLookupState:
//         str = "主机查找";
//         break;
//     case QAbstractSocket::ConnectingState:
//         str = "连接中";
//         break;
//     case QAbstractSocket::ConnectedState:
//         str = "已连接";
//         break;
//     case QAbstractSocket::BoundState:
//         str = "绑定";
//         break;
//     case QAbstractSocket::ClosingState:
//         str = "关闭中";
//         break;
//     case QAbstractSocket::ListeningState:
//         str = "监听中";
//         break;
//     default:
//         str = "未知状态";
//         break;
//     }
//     qDebug() << "状态改变：" << str;
//     emit tcp_client_status_changed(state);
// }

// /* ---------------------------------------- TCP 服务器 -------------------------------------------- */
// // 初始化
// void web_tcp::tcp_server_init()
// {
//     // 创建服务器对象
//     m_tcpServer = new QTcpServer(this);
// }

// // 监听指定ip和端口
// void web_tcp::tcp_server_listen(QString ip, quint16 port)
// {
//     // 监听
//     QHostAddress addr(ip);
//     m_tcpServer->listen(addr, port);
//     qDebug() << "**开始监听";
//     qDebug() << "**服务器地址：" << m_tcpServer->serverAddress().toString();
//     qDebug() << "**服务器端口：" << QString::number(m_tcpServer->serverPort());
// }
    
// // 停止监听
// void web_tcp::tcp_server_stop_listen()
// {
//     if(m_tcpServer->isListening())
//     {
//         m_tcpServer->close();
//     }
//     qDebug() << "**停止监听";
// }

// // 客户端接入槽函数
// // 为客户端创建QTcpSocket并连接到客户端
// // 每个客户端创建线程
// void web_tcp::tcp_server_new_connection_slot()
// {
//     qDebug() << "**有新的客户端接入";
//     // 获取客户端连接
//     QTcpSocket *client = m_tcpServer->nextPendingConnection();
//     // 获取客户端ip和端口
//     QString ip = client->peerAddress().toString();
//     quint16 port = client->peerPort();
//     qDebug() << "**客户端ip：" << ip;
//     qDebug() << "**客户端端口：" << QString::number(port);
//     // 创建线程
//     web_tcp_thread *thread = new web_tcp_thread(client);
//     // 线程结束时销毁
//     connect(thread, &web_tcp_thread::finished, thread, &web_tcp_thread::deleteLater);
//     // 线程开始运行
//     thread->start();
//     // 发送客户端接入信号
//     emit tcp_server_new_connection_signal(ip, port);
// }