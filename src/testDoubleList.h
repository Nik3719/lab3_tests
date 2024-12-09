#include <gtest/gtest.h>
#include "DoubleList.h"

// Тестовый класс для DoubleList
class DoubleListTest : public ::testing::Test {
protected:
    DoubleList list;

    void SetUp() override {
        list.LDPUSHT("A");
        list.LDPUSHT("B");
        list.LDPUSHT("C");
    }
};

// Тесты вставки элементов
TEST_F(DoubleListTest, PushHead) {
    list.LDPUSHH("D");
    EXPECT_EQ(list.LDGET(0), "D");
    EXPECT_EQ(list.LDGET(1), "A");
}

TEST_F(DoubleListTest, PushTail) {
    list.LDPUSHT("D");
    EXPECT_EQ(list.LDGET(3), "D");
}

// Тесты удаления элементов
TEST_F(DoubleListTest, DeleteHead) {
    list.LDDELH();
    EXPECT_EQ(list.LDGET(0), "B");
}

TEST_F(DoubleListTest, DeleteTail) {
    list.LDDELT();
    EXPECT_EQ(list.LDGET(1), "B");
}

TEST_F(DoubleListTest, DeleteByValueExists) {
    list.LDDELV("B");
    EXPECT_EQ(list.LDISINDEX("B"), -1);
}

TEST_F(DoubleListTest, DeleteByValueNotFound) {
    
    EXPECT_EQ(list.LDDELV("X"), "Element not found.\n");
}

// Тесты получения индексов и элементов
TEST_F(DoubleListTest, GetIndex) {
    EXPECT_EQ(list.LDISINDEX("B"), 1);
    EXPECT_EQ(list.LDISINDEX("X"), -1);
}

TEST_F(DoubleListTest, GetByIndexValid) {
    EXPECT_EQ(list.LDGET(0), "A");
    EXPECT_EQ(list.LDGET(2), "C");
}

TEST_F(DoubleListTest, GetByIndexInvalid) {
    EXPECT_THROW(list.LDGET(10), std::out_of_range);
}

// Тесты перегрузки оператора []
TEST_F(DoubleListTest, OperatorAccessValid) {
    EXPECT_EQ(list[0], "A");
    EXPECT_EQ(list[1], "B");
    EXPECT_EQ(list[2], "C");
}

TEST_F(DoubleListTest, OperatorAccessNegativeIndex) {
    EXPECT_EQ(list[-1], "C");  // Обход с конца
    EXPECT_EQ(list[-2], "B");
}

TEST_F(DoubleListTest, OperatorAccessOutOfRange) {
    EXPECT_THROW(list[10], std::out_of_range);
}

// Тесты на печать списка
TEST_F(DoubleListTest, PrintList) {
    testing::internal::CaptureStdout();
    list.PRINT();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A B C \n");
}


