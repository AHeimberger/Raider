#ifndef TESTCOLORS_H
#define TESTCOLORS_H

#include <QTest>
#include "Matrix.h"

class TestMatrix: public QObject
{
    Q_OBJECT

private slots:
    void create_2_by_2_matrix();
    void create 3_by_3_matrix();
};

#endif // TESTCOLORS_H

