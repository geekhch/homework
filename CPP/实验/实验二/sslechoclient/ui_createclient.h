/********************************************************************************
** Form generated from reading UI file 'createclient.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECLIENT_H
#define UI_CREATECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateClient
{
public:
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *CreateClient)
    {
        if (CreateClient->objectName().isEmpty())
            CreateClient->setObjectName(QStringLiteral("CreateClient"));
        CreateClient->resize(351, 235);
        textEdit = new QTextEdit(CreateClient);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(90, 80, 151, 31));
        label = new QLabel(CreateClient);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 50, 72, 15));
        pushButton = new QPushButton(CreateClient);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 160, 151, 31));

        retranslateUi(CreateClient);

        QMetaObject::connectSlotsByName(CreateClient);
    } // setupUi

    void retranslateUi(QDialog *CreateClient)
    {
        CreateClient->setWindowTitle(QApplication::translate("CreateClient", "\346\226\260\345\273\272\345\256\242\346\210\267\347\253\257", Q_NULLPTR));
        label->setText(QApplication::translate("CreateClient", "\350\276\223\345\205\245\347\253\257\345\217\243", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CreateClient", "\345\210\233\345\273\272\350\277\236\346\216\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateClient: public Ui_CreateClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECLIENT_H
