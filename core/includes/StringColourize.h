#ifndef STRINGCOLOURIZE_H
#define STRINGCOLOURIZE_H

#include <QTextStream>
#include <QString>
#include <QList>
#include <QPair>
#include <QMap>

#include "StringColourizeSettings.h"
#include "IStringOperation.h"
#include "Colors.h"


class StringColourize : public IStringOperation {
public:
    StringColourize(QTextStream &stream);
    void readSettings(QIODevice &device);
    void addHighlight(QPair<Colors::Color, StringColourizeSettings>);

public slots:
    void doStringOperation(const QString &content) override;

protected:
    void colorize(const Colors::Color &color, QString &string, const StringColourizeSettings &StringColourizeSettings);

private:
    QTextStream &_stream;
    QList<QPair<Colors::Color, StringColourizeSettings>> _operations;
};

#endif // STRINGCOLOURIZE_H
