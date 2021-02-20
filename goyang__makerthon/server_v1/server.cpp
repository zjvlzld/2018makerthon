#include "server.h"
#include "ui_server.h"

#include <QTcpServer>
#include <QTcpSocket>

server:: server(QObject* parent) : QTcpServer(parent)
{

}
void server::incomingConnection(int socketfd)
{
    QTcpSocket* client=new QTcpSocket(this); //클라리언트 소켓 새성
    client->setSocketDescriptor(socketfd); //소켓드스크립터 설정
    clients.insert(client); //클라이언트 집합에 새로 들어온 클라이언트 추가
    connect(client,SIGNAL(readyRead()),this,SLOT(readmsg()));

    foreach(QTcpSocket* otherClient,clients)
        otherClient->write(QString("connected").toUtf8());

}

void server::readmsg()
{
    QTcpSocket* client=(QTcpSocket*)sender(); //메시지가 들어온 클라이언트를 감지하는 함수 sender
    QString line=QString::fromUtf8(client->readLine());

    foreach(QTcpSocket* otherClient,clients)
        otherClient->write(line.toUtf8());


}
