#ifndef SETTINGS_H
#define SETTINGS_H

#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QByteArray>

class Settings {
public:
    Settings(QFile &settingsFile);
    bool load();
    const QString &getFileToSpy();
    const QString &getColourizeSettings();
    const QString &getUdpTransmissionSettings();

private:
    QFile &_settingsFile;
    QString _fileToSpy;
    QString _colourizeSettings;
    QString _udpTransmissionSettings;
};

#endif // SETTINGS_H
