#ifndef PARK_UI_H
#define PARK_UI_H

#include <QMainWindow>
#include "controller.h"

namespace Ui {
class park_ui;
}

class park_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit park_ui(QWidget *parent = nullptr);
    ~park_ui();

private:
    Ui::park_ui *ui;
};

#endif // PARK_UI_H
