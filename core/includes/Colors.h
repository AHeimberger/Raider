#ifndef COLORS_H
#define COLORS_H

#include <QString>
#include <QObject>
#include <QMetaProperty>
#include <QMetaEnum>

class Colors: public QObject {
    Q_OBJECT

public:
    enum Color { nocolor,
                 black,
                 red,
                 green,
                 yellow,
                 blue,
                 magenta,
                 cyan,
                 light_gray,
                 dark_gray,
                 light_red,
                 light_green,
                 light_yellow,
                 light_blue,
                 light_magenta,
                 light_cyan
               };
    Q_ENUMS(Color)

    static QString toString(Color color);
    static Colors::Color fromString(QString color);
    static QMap<Colors::Color, QString> getAnsiColorMap();
    static QString getAvailableColors();
};
Q_DECLARE_METATYPE(Colors::Color)


#endif // COLORS_H
