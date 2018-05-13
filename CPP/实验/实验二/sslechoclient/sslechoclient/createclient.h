#ifndef CREATECLIENT_H
#define CREATECLIENT_H

#include <QDialog>
#include "sslechoclient.h"
#include <QList>

namespace Ui {
class CreateClient;
}

class CreateClient : public QDialog
{
    Q_OBJECT

public:
    explicit CreateClient(QWidget *parent = 0);
    ~CreateClient();
    QList<SslEchoClient *> *client_list;

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateClient *ui;
};

#endif // CREATECLIENT_H
