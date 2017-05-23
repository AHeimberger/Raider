#include "TestColors.h"


void TestColors::convert_color_to_string() {
    QCOMPARE(Colors::toString(Colors::nocolor), QString("nocolor"));
    QCOMPARE(Colors::toString(Colors::black), QString("black"));
    QCOMPARE(Colors::toString(Colors::red), QString("red"));
    QCOMPARE(Colors::toString(Colors::green), QString("green"));
    QCOMPARE(Colors::toString(Colors::yellow), QString("yellow"));
    QCOMPARE(Colors::toString(Colors::blue), QString("blue"));
    QCOMPARE(Colors::toString(Colors::magenta), QString("magenta"));
    QCOMPARE(Colors::toString(Colors::cyan), QString("cyan"));
    QCOMPARE(Colors::toString(Colors::light_gray), QString("light_gray"));
    QCOMPARE(Colors::toString(Colors::dark_gray), QString("dark_gray"));
    QCOMPARE(Colors::toString(Colors::light_red), QString("light_red"));
    QCOMPARE(Colors::toString(Colors::light_green), QString("light_green"));
    QCOMPARE(Colors::toString(Colors::light_yellow), QString("light_yellow"));
    QCOMPARE(Colors::toString(Colors::light_blue), QString("light_blue"));
    QCOMPARE(Colors::toString(Colors::light_magenta), QString("light_magenta"));
    QCOMPARE(Colors::toString(Colors::light_cyan), QString("light_cyan"));
}

void TestColors::convert_string_to_color() {
    QCOMPARE(Colors::fromString("nocolor"), Colors::nocolor);
    QCOMPARE(Colors::fromString("black"),Colors::black);
    QCOMPARE(Colors::fromString("red"), Colors::red);
    QCOMPARE(Colors::fromString("green"), Colors::green);
    QCOMPARE(Colors::fromString("yellow"), Colors::yellow);
    QCOMPARE(Colors::fromString("blue"), Colors::blue);
    QCOMPARE(Colors::fromString("magenta"), Colors::magenta);
    QCOMPARE(Colors::fromString("cyan"), Colors::cyan);
    QCOMPARE(Colors::fromString("light_gray"), Colors::light_gray);
    QCOMPARE(Colors::fromString("dark_gray"), Colors::dark_gray);
    QCOMPARE(Colors::fromString("light_red"), Colors::light_red);
    QCOMPARE(Colors::fromString("light_green"), Colors::light_green);
    QCOMPARE(Colors::fromString("light_yellow"), Colors::light_yellow);
    QCOMPARE(Colors::fromString("light_blue"), Colors::light_blue);
    QCOMPARE(Colors::fromString("light_magenta"), Colors::light_magenta);
    QCOMPARE(Colors::fromString("light_cyan"), Colors::light_cyan);
}
