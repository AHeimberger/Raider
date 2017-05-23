#include "gtest/gtest.h"
#include "printto.h"
#include "helpers.h"
#include <QSignalSpy>
#include "FileReadOperations.h"

//
// read from end of file backwards
//
TEST(filereadoperations, file_does_not_exist_no_read_from_end_of_file_backward) {
    FileReadOperations testee("");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readFromEndOfFileBackward(1);

    ASSERT_EQ(0, spyReadString.count());
}

TEST(filereadoperations, expecting_last_line_of_file_to_be_read) {
    FileReadOperations testee(":/testobjects/filereadoperations_testfile.txt");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readFromEndOfFileBackward(1);

    ASSERT_EQ(1, spyReadString.count());
    QList<QVariant> arguments = spyReadString.takeFirst();
    EXPECT_EQ(getFileContent(":/testobjects/filereadoperations_testcompare_1.txt"), arguments.at(0).toString());
}

TEST(filereadoperations, expecting_last_two_lines_of_file_to_be_read) {
    FileReadOperations testee(":/testobjects/filereadoperations_testfile.txt");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readFromEndOfFileBackward(2);

    ASSERT_EQ(1, spyReadString.count());
    QList<QVariant> arguments = spyReadString.takeFirst();
    EXPECT_EQ(getFileContent(":/testobjects/filereadoperations_testcompare_2.txt"), arguments.at(0).toString());
}

TEST(filereadoperations, expecting_last_four_lines_of_file_to_be_read) {
    FileReadOperations testee(":/testobjects/filereadoperations_testfile.txt");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readFromEndOfFileBackward(4);

    ASSERT_EQ(1, spyReadString.count());
    QList<QVariant> arguments = spyReadString.takeFirst();
    EXPECT_EQ(getFileContent(":/testobjects/filereadoperations_testcompare_3.txt"), arguments.at(0).toString());
}

TEST(filereadoperations, although_trying_to_read_ten_lines_of_file_getting_only_four_because_no_more_entries) {
    FileReadOperations testee(":/testobjects/filereadoperations_testfile.txt");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readFromEndOfFileBackward(20);

    ASSERT_EQ(1, spyReadString.count());
    QList<QVariant> arguments = spyReadString.takeFirst();
    EXPECT_EQ(getFileContent(":/testobjects/filereadoperations_testcompare_3.txt"), arguments.at(0).toString());
}

//
// read complete file
//
TEST(filereadoperations, file_does_not_exist_no_read_complete_file) {
    FileReadOperations testee("");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readCompleteFile();

    ASSERT_EQ(0, spyReadString.count());
}

TEST(filereadoperations, file_exists_read_complete_file) {
    FileReadOperations testee(":/testobjects/filereadoperations_testfile.txt");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readCompleteFile();

    ASSERT_EQ(1, spyReadString.count());
    QList<QVariant> arguments = spyReadString.takeFirst();
    EXPECT_EQ(getFileContent(":/testobjects/filereadoperations_testcompare_3.txt"), arguments.at(0).toString());
}

//
// readFromPrevFileSizeTillEnd
//

TEST(FileReadOperations, file_does_not_exist_no_read_from_prev_file_size_till_end)
{
    FileReadOperations testee("");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readFromPrevFileSizeTillEnd(100);

    ASSERT_EQ(0, spyReadString.count());
}

TEST(FileReadOperations, prev_file_size_was_zero_so_read_complete_file)
{
    FileReadOperations testee(":/testobjects/filereadoperations_testfile.txt");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readFromPrevFileSizeTillEnd(0);

    ASSERT_EQ(1, spyReadString.count());
    QList<QVariant> arguments = spyReadString.takeFirst();
    EXPECT_EQ(getFileContent(":/testobjects/filereadoperations_testcompare_3.txt"), arguments.at(0).toString());
}


TEST(FileReadOperations, prev_file_size_was_50_so_read_rest_of_file)
{
    FileReadOperations testee(":/testobjects/filereadoperations_testfile.txt");
    QSignalSpy spyReadString(&testee, &FileReadOperations::readString);

    testee.readFromPrevFileSizeTillEnd(50);

    ASSERT_EQ(1, spyReadString.count());
    QList<QVariant> arguments = spyReadString.takeFirst();
    EXPECT_EQ(getFileContent(":/testobjects/filereadoperations_testcompare_4.txt"), arguments.at(0).toString());
}

