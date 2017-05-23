#ifndef PRINTTO_H
#define PRINTTO_H

#include <QString>
#include "Colors.h"
#include <iostream>

void PrintTo(const QString& string, ::std::ostream* os);
void PrintTo(const Colors::Color& color, ::std::ostream* os);

#endif // PRINTTO_H
