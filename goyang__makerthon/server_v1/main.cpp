#include "server.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    class server* server=new class server();
    bool success=server->listen(QHostAddress::Any,4200);
    if(!success)
    {
        return 0;
    }
    return a.exec();
}
