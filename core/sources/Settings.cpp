#include "Settings.h"

Settings::Settings(QFile &settingsFile) :
    _settingsFile(settingsFile),
    _fileToSpy(),
    _colourizeSettings(),
    _udpTransmissionSettings() {
}

bool Settings::load() {
    if (!_settingsFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Couldn't open file";
        return false;
    }

    QByteArray data = _settingsFile.readAll();
    QJsonObject jsonDoc = QJsonDocument::fromJson(data).object();
    _fileToSpy = jsonDoc["FileToSpy"].toString();
    _colourizeSettings = jsonDoc["StringColourize"].toString();
    _udpTransmissionSettings = jsonDoc["UdpTransmission"].toString();
    return true;
}

const QString &Settings::getFileToSpy() {
    return _fileToSpy;
}

const QString &Settings::getColourizeSettings() {
    return _colourizeSettings;
}

const QString &Settings::getUdpTransmissionSettings() {
    return _udpTransmissionSettings;
}
