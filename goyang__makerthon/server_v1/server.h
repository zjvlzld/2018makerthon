#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

class server : public QTcpServer
{
    Q_OBJECT
public:
    server(QObject* parent=0);

private slots:
    void readmsg(); //클라이언트로부터 메세지가 전달됨을 감지하는 함수

protected:
    void incomingConnection(int socketfd);  //처음 유저가 접속을 시도할때 발생하는 함수

private:
    int userAmount; //유저 닉네임에 번호를 매김
    QSet<QTcpSocket*> clients;  //클라이언트 소켓저장

};

#endif // SERVER_H
