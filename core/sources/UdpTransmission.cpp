#include "UdpTransmission.h"
#include <QDebug>
#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextStream>

UdpTransmission::UdpTransmission() :
    _udpSocket(),
    _enabled(false),
    _ip(),
    _port() {
}

void UdpTransmission::readSettings(QIODevice &device) {
    if ( device.open(QIODevice::ReadOnly) )
    {
        // QByteArray data = device.readAll(); // not working!
        QString data = device.readAll();
        device.close();

        // QJsonDocument json = QJsonDocument::fromBinaryData(data); // not working!
        QJsonDocument json = QJsonDocument::fromJson(data.toUtf8());
        QJsonObject object = json.object();
        _enabled = object["Enabled"].toBool();
        _ip = object["Ip"].toString();
        _port = object["Port"].toInt();
    }

    if (_enabled) {
        if (!_udpSocket.isNull() && _udpSocket->isOpen()) {
            _udpSocket->close();
        }

        _udpSocket = QSharedPointer<QUdpSocket>(new QUdpSocket(this));
    }
}

void UdpTransmission::doStringOperation(const QString &content) {
    if (_udpSocket.isNull()) {
        qDebug() << "Udp socket is not set.";
        return;
    }

    QHostAddress hostAddress(_ip);
    QByteArray data = content.toUtf8().data();
    _udpSocket->writeDatagram(data, hostAddress, _port);
}
