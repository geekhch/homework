#include "dialog.h"
#include "ui_dialog.h"
#include <QtCore/QDebug>
#include <QtWebSockets/QWebSocket>
#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"
#include <QTextStream>
#include <QPushButton>
#include <QException>
#include <QFileInfo>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    edit_1 = ui->textEdit;
    edit_2 = ui->textEdit_2;
    edit_1 -> setPlainText(m_savePath);
}

Dialog::~Dialog()
{
//    for(int i = 0; i < server_list->length(); i++)
//    {
//        delete server_list->at(i);
//    }
//    delete server_list;
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    exit(0);
}

//设置保存目录
void Dialog::on_pushButton_clicked()
{
    m_savePath = QFileDialog::getExistingDirectory() + '/';
    ui->textEdit->setPlainText(m_savePath);
}


//创建新的监听线程
void Dialog::on_pushButton_4_clicked()
{
    try{
        QString port = ui->textEdit_3->toPlainText();
        connect((new SslEchoServer(port.toInt())),&SslEchoServer::show_message,this,&Dialog::print_message);
        ports.append("、" + port);
        ui->textEdit_4->setPlainText(ports);
    }catch(QException e)
    {
        qDebug() << e.what();
    }

}

void Dialog::print_message(QString message){
    ui->textEdit_2->setPlainText(message);
    qDebug() << "message slot";
}
