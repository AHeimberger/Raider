#include "gtest/gtest.h"
#include "printto.h"

#include "Colors.h"

//
// get all available colors
//
TEST (colors, get_available_colors_string) {
    EXPECT_EQ("\e[39mnocolor\e[39m, \e[30mblack\e[39m, \e[31mred\e[39m, \e[32mgreen\e[39m, \e[33myellow\e[39m, \e[34mblue\e[39m, \e[35mmagenta\e[39m, \e[36mcyan\e[39m, \e[37mlight_gray\e[39m, \e[90mdark_gray\e[39m, \e[91mlight_red\e[39m, \e[92mlight_green\e[39m, \e[93mlight_yellow\e[39m, \e[94mlight_blue\e[39m, \e[95mlight_magenta\e[39m, \e[96mlight_cyan\e[39m", Colors::getAvailableColors());
}

//
// check enum color to string conversion
//
TEST (colors, check_enum_color_to_string_method) {
    EXPECT_EQ("nocolor", Colors::toString(Colors::Color::nocolor));
    EXPECT_EQ("red", Colors::toString(Colors::Color::red));
    EXPECT_EQ("green", Colors::toString(Colors::Color::green));
    EXPECT_EQ("yellow", Colors::toString(Colors::Color::yellow));
    EXPECT_EQ("blue", Colors::toString(Colors::Color::blue));
    EXPECT_EQ("magenta", Colors::toString(Colors::Color::magenta));
    EXPECT_EQ("cyan", Colors::toString(Colors::Color::cyan));
    EXPECT_EQ("light_gray", Colors::toString(Colors::Color::light_gray));
    EXPECT_EQ("light_red", Colors::toString(Colors::Color::light_red));
    EXPECT_EQ("light_green", Colors::toString(Colors::Color::light_green));
    EXPECT_EQ("light_yellow", Colors::toString(Colors::Color::light_yellow));
    EXPECT_EQ("light_blue", Colors::toString(Colors::Color::light_blue));
    EXPECT_EQ("light_magenta", Colors::toString(Colors::Color::light_magenta));
    EXPECT_EQ("light_cyan", Colors::toString(Colors::Color::light_cyan));
}

//
// check string to enum color conversion
//
TEST (colors, check_string_color_to_enum_method) {
    EXPECT_EQ(Colors::Color::nocolor, Colors::fromString("nocolor"));
    EXPECT_EQ(Colors::Color::red, Colors::fromString("red"));
    EXPECT_EQ(Colors::Color::green, Colors::fromString("green"));
    EXPECT_EQ(Colors::Color::yellow, Colors::fromString("yellow"));
    EXPECT_EQ(Colors::Color::blue, Colors::fromString("blue"));
    EXPECT_EQ(Colors::Color::magenta, Colors::fromString("magenta"));
    EXPECT_EQ(Colors::Color::cyan, Colors::fromString("cyan"));
    EXPECT_EQ(Colors::Color::light_gray, Colors::fromString("light_gray"));
    EXPECT_EQ(Colors::Color::light_red, Colors::fromString("light_red"));
    EXPECT_EQ(Colors::Color::light_green, Colors::fromString("light_green"));
    EXPECT_EQ(Colors::Color::light_yellow, Colors::fromString("light_yellow"));
    EXPECT_EQ(Colors::Color::light_blue, Colors::fromString("light_blue"));
    EXPECT_EQ(Colors::Color::light_magenta, Colors::fromString("light_magenta"));
    EXPECT_EQ(Colors::Color::light_cyan, Colors::fromString("light_cyan"));
}
