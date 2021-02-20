#include "home_ui.h"
#include "ui_home_ui.h"

home_ui::home_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home_ui)
{
    socket=new QTcpSocket(this);

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    socket->connectToHost("127.0.0.1",4200);


    ui->setupUi(this);
    QPixmap guard_pixmap(QApplication::applicationDirPath()+"/guard.bmp");
    QIcon guard_ButtonIcon(guard_pixmap);
    guard_pixmap = guard_pixmap.scaled(115,95);
    ui->GUARD_BUTTON->setIcon(guard_ButtonIcon);
    ui->GUARD_BUTTON->setIconSize(guard_pixmap.rect().size());

    QPixmap phone_pixmap(QApplication::applicationDirPath()+"/phone_img.jpg");
    QIcon phone_ButtonIcon(phone_pixmap);
    phone_pixmap = phone_pixmap.scaled(115,95);
    ui->PHONE_BUTTON->setIcon(phone_ButtonIcon);
    ui->PHONE_BUTTON->setIconSize(phone_pixmap.rect().size());

    QPixmap gate_pixmap(QApplication::applicationDirPath()+"/gate_img.jpg");
    QIcon gate_ButtonIcon(gate_pixmap);
    gate_pixmap = gate_pixmap.scaled(115,95);
    ui->GATE_BUTTON->setIcon(gate_ButtonIcon);
    ui->GATE_BUTTON->setIconSize(gate_pixmap.rect().size());

    QPixmap park_pixmap(QApplication::applicationDirPath()+"/park_img.jpg");
    QIcon park_ButtonIcon(park_pixmap);
    park_pixmap = park_pixmap.scaled(115,95);
    ui->PARK_BUTTON->setIcon(park_ButtonIcon);
    ui->PARK_BUTTON->setIconSize(park_pixmap.rect().size());

    QPixmap cctv_pixmap(QApplication::applicationDirPath()+"/cctv_img.jpg");
    QIcon cctv_ButtonIcon(cctv_pixmap);
    cctv_pixmap = cctv_pixmap.scaled(115,95);
    ui->CCTV_BUTTON->setIcon(cctv_ButtonIcon);
    ui->CCTV_BUTTON->setIconSize(cctv_pixmap.rect().size());

    QPixmap setting_pixmap(QApplication::applicationDirPath()+"/setting_img.jpg");
    QIcon setting_ButtonIcon(setting_pixmap);
    setting_pixmap = setting_pixmap.scaled(115,95);
    ui->SETTING->setIcon(setting_ButtonIcon);
    ui->SETTING->setIconSize(setting_pixmap.rect().size());

    QPixmap park_info_camara_pixmap(QApplication::applicationDirPath()+"/cctv_img.jpg");
    QIcon  park_info_camara_ButtonIcon( park_info_camara_pixmap);
     park_info_camara_pixmap =  park_info_camara_pixmap.scaled(125,105);
    ui->PARK1_camera->setIcon( park_info_camara_ButtonIcon);
    ui->PARK1_camera->setIconSize( park_info_camara_pixmap.rect().size());


    connect(ui->SETTING,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(ui->CCTV_BUTTON,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(ui->GUARD_BUTTON,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(ui->GATE_BUTTON,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(ui->PHONE_BUTTON,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(ui->PARK_BUTTON,SIGNAL(clicked()),this,SLOT(park_button_clicked()));
    connect(ui->PARKscene_4,SIGNAL(clicked()),this,SLOT(return_home_clicked()));
    connect(ui->PARKscene_3,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(ui->PARKscene_2,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(ui->PARKscene,SIGNAL(clicked()),this,SLOT(park_info_button_clicked()));
    connect(ui->PARK1_camera,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(ui->PARK1_go_PARK2,SIGNAL(clicked()),this,SLOT(button_clicked()));
    connect(ui->PARK1_go_HOME,SIGNAL(clicked()),this,SLOT(return_home_clicked()));
    connect(ui->PARK1_go_Park_select,SIGNAL(clicked()),this,SLOT(park_button_clicked()));

    ui->PARKscene->hide();
    ui->PARKscene_2->hide();
    ui->PARKscene_3->hide();
    ui->PARKscene_4->hide();
    ui->PARK_SCENE_TITLE->hide();

    ui->PARK1_1->hide();
    ui->PARK1_2->hide();
    ui->PARK1_3->hide();
    ui->PARK1_4->hide();
    ui->PARK1_5->hide();
    ui->PARK1_6->hide();
    ui->PARK1_BACKGROUND->hide();
    ui->PARK1_camera->hide();
    ui->PARK1_camera_txt->hide();
    ui->PARK1_go_HOME->hide();
    ui->PARK1_go_PARK2->hide();
    ui->PARK1_go_Park_select->hide();
    ui->PARK_INFO_SCENE_2->hide();
}

void home_ui::return_home_clicked()
{

    ui->CCTV_BUTTON->show();
    ui->CCTV_TITLE->show();
    ui->GATE_BUTTON->show();
    ui->GATE_TITLE->show();
    ui->GUARD_BUTTON->show();
    ui->GUARD_TITLE->show();
    ui->PARK_BUTTON->show();
    ui->PARK_TITLE->show();
    ui->PHONE_BUTTON->show();
    ui->PHONE_TITLE->show();
    ui->SETTING->show();
    ui->SETTING_TITLE->show();
    ui->TITLE_BUTTON->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();

    ui->PARKscene->hide();
    ui->PARKscene_2->hide();
    ui->PARKscene_3->hide();
    ui->PARKscene_4->hide();
    ui->PARK_SCENE_TITLE->hide();

    ui->PARK1_1->hide();
    ui->PARK1_2->hide();
    ui->PARK1_3->hide();
    ui->PARK1_4->hide();
    ui->PARK1_5->hide();
    ui->PARK1_6->hide();
    ui->PARK1_BACKGROUND->hide();
    ui->PARK1_camera->hide();
    ui->PARK1_camera_txt->hide();
    ui->PARK1_go_HOME->hide();
    ui->PARK1_go_PARK2->hide();
    ui->PARK1_go_Park_select->hide();
    ui->PARK_INFO_SCENE_2->hide();
}

void home_ui::readyRead()
{
    QString get;

        get=socket->readLine();
        QStringList info;
        QList<QString> tt;
        for(int i=0;i<200;i++)
        {
            tt.append("a");
            info.append("");
        }
        int fill=0;
        info=get.split("/@/");
        for(int i=0;i<info.size();i++)
        {
            tt[i]=info[i];
        }
        if(tt[2]=="1")
        {
            ui->PARK1_1->setStyleSheet("background-color: red;");
            fill++;
        }
        else if(tt[2]=="0")
        {
            ui->PARK1_1->setStyleSheet("background-color: green;");
        }
        if(tt[3]=="1")
        {
            ui->PARK1_2->setStyleSheet("background-color: red;");
            fill++;

        }
        else if(tt[3]=="0")
        {
            ui->PARK1_2->setStyleSheet("background-color: green;");
        }
        if(tt[4]=="1")
        {
            ui->PARK1_3->setStyleSheet("background-color: red;");
            fill++;

        }
        else if(tt[4]=="0")
        {
            ui->PARK1_3->setStyleSheet("background-color: green;");
        }
        if(tt[5]=="1")
        {
            ui->PARK1_4->setStyleSheet("background-color: red;");
            fill++;

        }
        else if(tt[5]=="0")
        {
            ui->PARK1_4->setStyleSheet("background-color: green;");
        }
        if(tt[6]=="1")
        {
            ui->PARK1_5->setStyleSheet("background-color: red;");
            fill++;

        }
        else if(tt[6]=="0")
        {
            ui->PARK1_5->setStyleSheet("background-color: green;");
        }

        if(tt[7]=="1")
        {
            ui->PARK1_6->setStyleSheet("background-color: red;");
            fill++;
        }
        else if(tt[7]=="0")
        {
            ui->PARK1_6->setStyleSheet("background-color: green;");
        }

}

void home_ui::park_info_button_clicked()
{
    ui->CCTV_BUTTON->hide();
    ui->CCTV_TITLE->hide();
    ui->GATE_BUTTON->hide();
    ui->GATE_TITLE->hide();
    ui->GUARD_BUTTON->hide();
    ui->GUARD_TITLE->hide();
    ui->PARK_BUTTON->hide();
    ui->PARK_TITLE->hide();
    ui->PHONE_BUTTON->hide();
    ui->PHONE_TITLE->hide();
    ui->SETTING->hide();
    ui->SETTING_TITLE->hide();
    ui->TITLE_BUTTON->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();

    ui->PARKscene->hide();
    ui->PARKscene_2->hide();
    ui->PARKscene_3->hide();
    ui->PARKscene_4->hide();
    ui->PARK_SCENE_TITLE->hide();

    ui->PARK1_1->show();
    ui->PARK1_2->show();
    ui->PARK1_3->show();
    ui->PARK1_4->show();
    ui->PARK1_5->show();
    ui->PARK1_6->show();
    ui->PARK1_BACKGROUND->show();
    ui->PARK1_camera->show();
    ui->PARK1_camera_txt->show();
    ui->PARK1_go_HOME->show();
    ui->PARK1_go_PARK2->show();
    ui->PARK1_go_Park_select->show();
    ui->PARK_INFO_SCENE_2->show();
}

void home_ui::button_clicked()
{
    QMessageBox *alert_box=new QMessageBox();
    alert_box->setWindowTitle("sorry, this is test Version");
    alert_box->setText((QString)"This is Test Version.\nPlease wait for the Full Version!");
    alert_box->show();
    return;
}

void home_ui::park_button_clicked()
{
    ui->CCTV_BUTTON->hide();
    ui->CCTV_TITLE->hide();
    ui->GATE_BUTTON->hide();
    ui->GATE_TITLE->hide();
    ui->GUARD_BUTTON->hide();
    ui->GUARD_TITLE->hide();
    ui->PARK_BUTTON->hide();
    ui->PARK_TITLE->hide();
    ui->PHONE_BUTTON->hide();
    ui->PHONE_TITLE->hide();
    ui->SETTING->hide();
    ui->SETTING_TITLE->hide();
    ui->TITLE_BUTTON->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();

    ui->PARKscene->show();
    ui->PARKscene_2->show();
    ui->PARKscene_3->show();
    ui->PARKscene_4->show();
    ui->PARK_SCENE_TITLE->show();

    ui->PARK1_1->hide();
    ui->PARK1_2->hide();
    ui->PARK1_3->hide();
    ui->PARK1_4->hide();
    ui->PARK1_5->hide();
    ui->PARK1_6->hide();
    ui->PARK1_BACKGROUND->hide();
    ui->PARK1_camera->hide();
    ui->PARK1_camera_txt->hide();
    ui->PARK1_go_HOME->hide();
    ui->PARK1_go_PARK2->hide();
    ui->PARK1_go_Park_select->hide();
    ui->PARK_INFO_SCENE_2->hide();
}


home_ui::~home_ui()
{
    delete ui;
}
