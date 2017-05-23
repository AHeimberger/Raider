#include "StringColourize.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDebug>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

StringColourize::StringColourize(QTextStream &stream) :
    _stream(stream) {

}

void StringColourize::readSettings(QIODevice &device) {
    if ( device.open(QIODevice::ReadOnly) ) {
        // QByteArray data = device.readAll(); // not working!
        QString data = device.readAll();
        device.close();

        // QJsonDocument json = QJsonDocument::fromBinaryData(data); // not working!
        QJsonDocument json = QJsonDocument::fromJson(data.toUtf8());
        QJsonObject object = json.object();
        QJsonArray array = object["RegularExpressions"].toArray();
        for (int i = 0; i < array.size(); ++i) {
            QJsonObject obj = array[i].toObject();
            QString strColor = obj["color"].toString();
            StringColourizeSettings StringColourizeSettings;
            StringColourizeSettings._preDelimiter = obj["preDelimiter"].toString();
            StringColourizeSettings._regex = obj["regex"].toString();
            StringColourizeSettings._postDelimiter = obj["postDelimiter"].toString();
            Colors::Color color = Colors::fromString(strColor);
            _operations.append(qMakePair(color, StringColourizeSettings));
            qDebug() << "Colourize setting:" << strColor << StringColourizeSettings._regex;
        }
    }
}

void StringColourize::addHighlight(QPair<Colors::Color, StringColourizeSettings> highlight) {
    _operations.append(highlight);
}

void StringColourize::doStringOperation(const QString &content) {
    QString string = content;
    for (auto value: _operations) {
        colorize(value.first, string, value.second);
    }
    _stream << string;
    _stream.flush();
}

void StringColourize::colorize(const Colors::Color &color, QString &string, const StringColourizeSettings &StringColourizeSettings) {
    QString resetColor = Colors::getAnsiColorMap().value(Colors::Color::nocolor);
    QString strColor = Colors::getAnsiColorMap().value(color);
    if (strColor == resetColor)
        return;

    QString fullRegex = QString("%1%2%3")
            .arg(StringColourizeSettings._preDelimiter)
            .arg(StringColourizeSettings._regex)
            .arg(StringColourizeSettings._postDelimiter);

    int preDelimiterLength = StringColourizeSettings._preDelimiter.length();
    int postDelimiterLength = StringColourizeSettings._postDelimiter.length();

    QRegularExpression re = QRegularExpression(fullRegex);
    QRegularExpressionMatchIterator i = re.globalMatch(string);

    int insertCnt = 0;
    int charactersToInsert = (resetColor + strColor).length();
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        if (match.hasMatch()) {
            int stop = (match.capturedEnd() - postDelimiterLength);
            string.insert(stop + (insertCnt * charactersToInsert), resetColor);
            int start = (match.capturedStart() + preDelimiterLength);
            string.insert(start + (insertCnt * charactersToInsert), strColor);
        }

        ++insertCnt;
    }
}
