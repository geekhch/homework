#include "createclient.h"
#include "ui_createclient.h"

CreateClient::CreateClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateClient)
{
    ui->setupUi(this);
}

CreateClient::~CreateClient()
{
    delete ui;
}

void CreateClient::on_pushButton_clicked()
{
    QString port = ui->textEdit->toPlainText();
    client_list->append(new SslEchoClient(QUrl(QString("wss://localhost:" + port))));
    qDebug() << "创建新连接，端口为" << port;
}
