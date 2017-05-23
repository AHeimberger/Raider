#include "gtest/gtest.h"
#include "printto.h"
#include "helpers.h"
#include "StringColourize.h"
#include <QTextStream>

//
// try simple string colorization
//
TEST(stringcolourize, string_does_not_get_colorized_because_no_settings_given_to_testee) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    testee.doStringOperation("hello world");

    EXPECT_EQ("hello world", QString::fromUtf8(array));
}

TEST(stringcolourize, string_does_not_get_colorized_because_hello_not_in_sentence) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = "";
    settings._preDelimiter = "";
    settings._regex = "hello";
    newHighlight.first = Colors::Color::red;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    testee.doStringOperation("goodbye world");

    EXPECT_EQ("goodbye world", QString::fromUtf8(array));
}

TEST(stringcolourize, hello_in_string_gets_colored_red) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = "";
    settings._preDelimiter = "";
    settings._regex = "hello";
    newHighlight.first = Colors::Color::red;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    testee.doStringOperation("hello world");

    EXPECT_EQ("\e[31mhello\e[39m world", QString::fromUtf8(array));
}

TEST(stringcolourize, hello_in_string_gets_colored_blue) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = "";
    settings._preDelimiter = "";
    settings._regex = "hello";
    newHighlight.first = Colors::Color::blue;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    testee.doStringOperation("hello world");

    EXPECT_EQ("\e[34mhello\e[39m world", QString::fromUtf8(array));
}

TEST(stringcolourize, hello_in_string_gets_colored_blue_world_gets_color_red) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = "";
    settings._preDelimiter = "";
    settings._regex = "hello";
    newHighlight.first = Colors::Color::blue;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    settings._postDelimiter = "";
    settings._preDelimiter = "";
    settings._regex = "world";
    newHighlight.first = Colors::Color::red;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);


    testee.doStringOperation("hello world");

    EXPECT_EQ("\e[34mhello\e[39m \e[31mworld\e[39m", QString::fromUtf8(array));
}


//
// try some more advanced regular expressions
//
TEST(stringcolourize, colorize_the_date_within_the_string) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = "";
    settings._preDelimiter = "";
    settings._regex = R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})";
    newHighlight.first = Colors::Color::green;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    testee.doStringOperation("this is 2017-05-23 21:58:15 and i do some shitty tests");

    EXPECT_EQ("this is \e[32m2017-05-23 21:58:15\e[39m and i do some shitty tests", QString::fromUtf8(array));
}

TEST(stringcolourize, all_four_letter_words_get_colored_in_green) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = "";
    settings._preDelimiter = "";
    settings._regex = R"(\b\w{4}\b)";
    newHighlight.first = Colors::Color::green;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    testee.doStringOperation("all four letter words get colored, have some fun");

    EXPECT_EQ("all \e[32mfour\e[39m letter words get colored, \e[32mhave\e[39m \e[32msome\e[39m fun", QString::fromUtf8(array));
}

//
// try simple string colorization
//
TEST(stringcolourize, pre_and_post_delimiter_were_not_found_no_colorization) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = " ";
    settings._preDelimiter = " ";
    settings._regex = R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})";
    newHighlight.first = Colors::Color::green;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    testee.doStringOperation("2017-05-23 21:58:15");

    EXPECT_EQ("2017-05-23 21:58:15", QString::fromUtf8(array));
}

TEST(stringcolourize, pre_delimiter_was_found_colorize_string) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = "";
    settings._preDelimiter = " ";
    settings._regex = R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})";
    newHighlight.first = Colors::Color::green;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    testee.doStringOperation(" 2017-05-23 21:58:15");

    EXPECT_EQ(" \e[32m2017-05-23 21:58:15\e[39m", QString::fromUtf8(array));
}

TEST(stringcolourize, post_delimiter_was_found_colorize_string) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = " ";
    settings._preDelimiter = "";
    settings._regex = R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})";
    newHighlight.first = Colors::Color::green;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    testee.doStringOperation("2017-05-23 21:58:15 ");

    EXPECT_EQ("\e[32m2017-05-23 21:58:15\e[39m ", QString::fromUtf8(array));
}

TEST(stringcolourize, pre_and_post_delimiter_were_found_colorize_string) {
    QByteArray array;
    QTextStream stream(&array);
    StringColourize testee(stream);

    QPair<Colors::Color, StringColourizeSettings> newHighlight;
    StringColourizeSettings settings;
    settings._postDelimiter = " ";
    settings._preDelimiter = " ";
    settings._regex = R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})";
    newHighlight.first = Colors::Color::green;
    newHighlight.second = settings;
    testee.addHighlight(newHighlight);

    testee.doStringOperation(" 2017-05-23 21:58:15 ");

    EXPECT_EQ(" \e[32m2017-05-23 21:58:15\e[39m ", QString::fromUtf8(array));
}
