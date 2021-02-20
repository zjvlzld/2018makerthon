#include "park_ui.h"
#include "ui_park_ui.h"

park_ui::park_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::park_ui)
{
    ui->setupUi(this);
}

park_ui::~park_ui()
{
    delete ui;
}
