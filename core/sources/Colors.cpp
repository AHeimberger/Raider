#include "Colors.h"
#include <QMapIterator>

static QMetaEnum getEnumerator(const QMetaObject &mObject, const QString &enumName) {
    int enumIdx = mObject.indexOfEnumerator(enumName.toUtf8().data());
    return mObject.enumerator(enumIdx);
}

QString Colors::toString(Colors::Color color) {
    return getEnumerator(Colors::staticMetaObject, "Color").valueToKey(static_cast<int>(color));
}

Colors::Color Colors::fromString(QString color) {
    return static_cast<Color>(getEnumerator(Colors::staticMetaObject, "Color").keyToValue(color.toUtf8().data()));
}

QMap<Colors::Color, QString> Colors::getAnsiColorMap() {
    QMap<Colors::Color, QString> colorMap;
    colorMap[Colors::Color::nocolor]		= "\e[39m";
    colorMap[Colors::Color::black]			= "\e[30m";
    colorMap[Colors::Color::red]			= "\e[31m";
    colorMap[Colors::Color::green]			= "\e[32m";
    colorMap[Colors::Color::yellow]         = "\e[33m";
    colorMap[Colors::Color::blue]			= "\e[34m";
    colorMap[Colors::Color::magenta]		= "\e[35m";
    colorMap[Colors::Color::cyan]			= "\e[36m";
    colorMap[Colors::Color::light_gray]     = "\e[37m";
    colorMap[Colors::Color::dark_gray]		= "\e[90m";
    colorMap[Colors::Color::light_red]		= "\e[91m";
    colorMap[Colors::Color::light_green]	= "\e[92m";
    colorMap[Colors::Color::light_yellow]	= "\e[93m";
    colorMap[Colors::Color::light_blue]     = "\e[94m";
    colorMap[Colors::Color::light_magenta]	= "\e[95m";
    colorMap[Colors::Color::light_cyan]     = "\e[96m";
    return colorMap;
}

QString Colors::getAvailableColors() {
    QMap<Colors::Color, QString> colorMap = getAnsiColorMap();
    QMapIterator<Colors::Color, QString> it(colorMap);
    QStringList values;
    while (it.hasNext()) {
        it.next();
        QString color = QString("%1%2%3")
                .arg(it.value())
                .arg(Colors::toString(it.key()))
                .arg(colorMap.value(Colors::Color::nocolor));
        values << color;
    }
    return values.join(", ");
}
