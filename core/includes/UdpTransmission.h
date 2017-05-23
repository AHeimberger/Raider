#ifndef UDPTRANSMISSION_H
#define UDPTRANSMISSION_H

#include <QSharedPointer>
#include <QUdpSocket>
#include <QIODevice>

#include "IStringOperation.h"

class UdpTransmission : public IStringOperation {
public:
    UdpTransmission();
    void readSettings(QIODevice &device);

public slots:
    void doStringOperation(const QString &content) override;

private:
    QSharedPointer<QUdpSocket> _udpSocket;
    bool _enabled;
    QString _ip;
    int _port;
};

#endif // UDPTRANSMISSION_H
