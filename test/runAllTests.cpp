#include "gtest/gtest.h"
#include "UserTest.cpp"
#include "ListTest.cpp"
#include "ItemTest.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}