#include "printto.h"

void PrintTo(const QString& string, ::std::ostream* os) {
  *os << string.toUtf8().data();
}

void PrintTo(const Colors::Color& color, ::std::ostream* os) {
  *os << Colors::toString(color).toUtf8().data();
}
