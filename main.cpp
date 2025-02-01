#include <QCoreApplication>
#include "server.h"
#include <csignal>
void signalHandler(int signal) {
    qDebug() << "Received signal:" << signal;
    QCoreApplication::quit();
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::signal(SIGINT, signalHandler);

    Server s;

    return a.exec();
}
