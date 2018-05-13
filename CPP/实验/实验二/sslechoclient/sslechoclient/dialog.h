#ifndef DIALOG_H
#define DIALOG_H

#include <QtCore/QCoreApplication>
#include <QDialog>
#include <QTextCodec>
#include <QThread>
#include <QFileDialog>
#include <QTextEdit>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog //, public QThread
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    void run();

public:
    QString img_name;
    QTextEdit *m_textEdit;
    QPushButton *m_pushButton;
    QPushButton *m_pushButton_2;
};

#endif // DIALOG_H
