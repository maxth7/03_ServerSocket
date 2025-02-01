#include "server.h"
#include "ffile.h"

Server::Server(){
    if(this->listen(QHostAddress::Any,4444)){
        qDebug()<<"start";
    }else{
        qDebug()<<"error";
    }
    nextBlockSize=0;
}
void Server::incomingConnection(qintptr socketDescriptor){
    socket=new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket,&QTcpSocket::readyRead,this,&Server::slotReadyReadSocket);
    connect(socket,&QTcpSocket::disconnected,socket,&QTcpSocket::deleteLater);
    Socket.push_back(socket);
    SendToClient("!"+ QString::number(socketDescriptor));
    clientNumber++;
    qDebug() <<QString::number(clientNumber)+")socketDescriptor="<<QString::number(socketDescriptor);
}
void Server::slotReadyReadSocket(){
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_8);

    if (socket->state() != QAbstractSocket::ConnectedState) {
        qDebug() << "Socket is not connected.";
        return;
    }

    if (in.status() == QDataStream::Ok) {
        while (true) {
            if (nextBlockSize == 0) {

                if (static_cast<quint64>(socket->bytesAvailable()) < sizeof(quint16)) {
                    break;
                }
                in >> nextBlockSize;
            }

            if (socket->bytesAvailable() < nextBlockSize) {
                break;
            }

            QString str;
            QString strToClient;
            in >> str;

            nextBlockSize = 0;

            std::string searchPattern = str.toStdString();

            bool exit=false;
            strToClient=ff.findPatternStringInFilename(searchPattern, exit);
          SendToClient(strToClient);
            break;
        }// While------------------------------
    } else {
        QString err= "?From Server DataStream error.";

        SendToClient( "?From Server DataStream error.");
    }
}

void Server::SendToClient(QString str){
    Data.clear();

    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_8);

    out<<quint16(0)<<str;
    out.device()->seek(0);
    out<<quint16(Data.size()-sizeof(quint16));

    out<<str;
   socket->write(Data);

}

