#ifndef HOME_UI_H
#define HOME_UI_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QMessageBox>
#include <QIcon>
#include <QTcpSocket>

#include "controller.h"
#include "park_ui.h"

namespace Ui {
class home_ui;
}

class home_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit home_ui(QWidget *parent = nullptr);
    ~home_ui();

public slots:
    void button_clicked();
    void park_button_clicked();
    void return_home_clicked();
    void park_info_button_clicked();

    void readyRead(); //서버로부터 메시지가 온경우



private:
    Ui::home_ui *ui;
    QTcpSocket* socket; //나의 소켓
};

#endif // HOME_UI_H
