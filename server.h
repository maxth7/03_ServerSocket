#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>
#include <QDebug>

#include <QDir>
#include <QFileInfoList>
#include <QString>

#include "ffile.h"

class Server : public QTcpServer{
    Q_OBJECT
public:
    Server();

    QTcpSocket *socket;
    Ffile ff;
    int clientNumber=0;
private:
    QVector <QTcpSocket*> Socket;
    QByteArray Data;
    void SendToClient(QString str);
    quint16 nextBlockSize;

public slots:
    void incomingConnection(qintptr socketDeskritor);
    void slotReadyReadSocket();
};

#endif // SERVER_H
