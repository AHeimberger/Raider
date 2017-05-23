#ifndef TESTCOLORS_H
#define TESTCOLORS_H

#include <QTest>
#include "Colors.h"

class TestColors: public QObject
{
    Q_OBJECT

private slots:
    void convert_color_to_string();
    void convert_string_to_color();
};

#endif // TESTCOLORS_H

