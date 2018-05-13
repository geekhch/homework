/******00**********************************************************************
**
** Copyright (C) 2016 Kurt Pattyn <pattyn.kurt@gmail.com>.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWebSockets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "sslechoclient.h"
#include <QtCore/QDebug>
#include <QtWebSockets/QWebSocket>
#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QTextStream>
#include <QPushButton>
#include <QFileInfo>
using namespace  std;

QT_USE_NAMESPACE

//! [constructor]
SslEchoClient::SslEchoClient(const QUrl &url, QObject *parent) : QObject(parent)
{
    ssl_dia.show();
    QCoreApplication::processEvents();
    connect(&m_webSocket, &QWebSocket::connected, this, &SslEchoClient::onConnected);
    typedef void (QWebSocket:: *sslErrorsSignal)(const QList<QSslError> &);
    connect(&m_webSocket, static_cast<sslErrorsSignal>(&QWebSocket::sslErrors), this, &SslEchoClient::onSslErrors);
    m_webSocket.open(QUrl(url));
}

void SslEchoClient::onConnected()
{
    m_webSocket.sendTextMessage(QStringLiteral("Hello, world! Server,I'am client!"));
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &SslEchoClient::onTextMessageReceived);
    connect(ssl_dia.m_pushButton, &QPushButton::clicked,this, &SslEchoClient::sendMessage);
    connect(ssl_dia.m_pushButton_2, &QPushButton::clicked,this, &SslEchoClient::sendFile);

}

void SslEchoClient::onTextMessageReceived(QString message)
{
    ssl_dia.m_textEdit->setPlainText(message);
}

void SslEchoClient::onSslErrors(const QList<QSslError> &errors)
{
    Q_UNUSED(errors);

    // WARNING: Never ignore SSL errors in production code.
    // The proper way to handle self-signed certificates is to add a custom root
    // to the CA store.

    qDebug() << "ssl Error!";
    m_webSocket.ignoreSslErrors();
}

void SslEchoClient::sendMessage()
{
    QString message = ssl_dia.m_textEdit->toPlainText();
    m_webSocket.sendTextMessage(message);
}

void SslEchoClient::sendFile()
{
    try{
        QString path = QFileDialog::getOpenFileName(&ssl_dia, tr("Select File To Send"),".",tr("File(*)"));
        if(path.length()<1) return;
        QFileInfo info(path);
        QString file_name = info.fileName();
        //文件发送消息标记协议
        m_webSocket.sendTextMessage("f:" + file_name);
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "Can't open file for writing";
            return;
        }
//        out.setVersion(QDataStream::Qt_5_8);
        qDebug() << "read";
        QByteArray byte = file.readAll();
        m_webSocket.sendBinaryMessage(byte);
        qDebug() << "send";
        file.close();
    }catch(exception e){
        e.what();
    }
}
