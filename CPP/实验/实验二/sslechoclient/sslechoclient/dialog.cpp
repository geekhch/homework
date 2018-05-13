#include "dialog.h"
#include <string>
#include "ui_dialog.h"
using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    m_textEdit = ui->textEdit;
    m_pushButton = ui->pushButton;
    m_pushButton_2 = ui->pushButton_2;
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::run()
{
    while(true);
}
