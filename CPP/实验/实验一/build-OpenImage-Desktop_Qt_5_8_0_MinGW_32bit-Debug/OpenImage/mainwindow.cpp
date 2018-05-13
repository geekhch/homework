#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTextCodec>
#include <string>
#include <QString>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    img_name = QFileDialog::getOpenFileName( this, tr("Open Image"), ".",tr("Image Files(*.png *.jpg *.jpeg *.bmp)"));
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    string name = code->fromUnicode(img_name).data();
    if(name.length()<1) return;
    qDebug() << "打开图片：" << img_name;

    try{
        src=imread(img_name.toUtf8().data());
        namedWindow( "src", WINDOW_NORMAL);
        if(!src.empty()){
            imshow("src",src);
        }
    }catch(Exception e){
        cout << e.err << endl;
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}

//实现灰度图和彩色图之间的相互转换
void MainWindow::on_pushButton_3_clicked()
{
    try{
        if(colorful)
        {
            cvtColor(src, src, COLOR_RGB2GRAY);
            imshow("src",src);
        }
        else
        {
            src=imread(img_name.toUtf8().data());//
            imshow("src",src);
        }
        colorful = !colorful;
    }catch(Exception e){
        cout << e.err << endl;
    }
}
