#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <sslechoserver.h>
#include <QList>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

//    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    //自定义信号槽函数，接收客户端发来的消息
    void print_message(QString message);

private:
    Ui::Dialog *ui;
//    QList<SslEchoServer *> *server_list;


public:
    QTextEdit *edit_1;
    QTextEdit *edit_2;
    //默认保存路径
    QString m_savePath = "C:/Users/hch/Desktop/websocket/";
    QString ports;
};

#endif // DIALOG_H
