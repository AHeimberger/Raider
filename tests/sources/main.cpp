#include "gtest/gtest.h"
#include "helpers.h"

int main(int argc, char **argv) {
    qInstallMessageHandler(msgHandler);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
