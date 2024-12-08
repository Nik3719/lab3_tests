#include "stack.h"
#include <gtest/gtest.h>
#include <sstream>
using namespace std;

// Тесты для конструктора
TEST(StackTest, ConstructorCreatesEmptyStack) {
    Stack s;
    EXPECT_TRUE(s.isEmpty());
}

// Тесты для метода SPUSH
TEST(StackTest, SPUSH_AddsElements) {
    Stack s;
    s.SPUSH("A");
    EXPECT_FALSE(s.isEmpty());
    EXPECT_EQ(s.SPOP(), "A");
}

// Тесты для метода SPOP
TEST(StackTest, SPOP_RemovesAndReturnsLastElement) {
    Stack s;
    s.SPUSH("A");
    s.SPUSH("B");
    EXPECT_EQ(s.SPOP(), "B");
    EXPECT_EQ(s.SPOP(), "A");
}

TEST(StackTest, SPOP_OnEmptyStack) {
    Stack s;
    EXPECT_EQ(s.SPOP(), "Пустой стек\n");
}

// Тесты для метода SGET
TEST(StackTest, SGET_ValidIndex) {
    Stack s;
    s.SPUSH("A");
    s.SPUSH("B");
    s.SPUSH("C");
    EXPECT_EQ(s.SGET(2), "C");
    EXPECT_EQ(s.SGET(1), "B");
    EXPECT_EQ(s.SGET(0), "A");
}

TEST(StackTest, SGET_InvalidIndex) {
    Stack s;
    s.SPUSH("A");
    EXPECT_EQ(s.SGET(5), "A");  // С учетом функции mod
}

// Тесты для оператора []
TEST(StackTest, OperatorIndex_ValidIndex) {
    Stack s;
    s.SPUSH("X");
    s.SPUSH("Y");
    s.SPUSH("Z");
    EXPECT_EQ(s[2], "Z");
    EXPECT_EQ(s[1], "Y");
    EXPECT_EQ(s[0], "X");
}

TEST(StackTest, OperatorIndex_ModuloAccess) {
    Stack s;
    s.SPUSH("A");
    s.SPUSH("B");
    s.SPUSH("C");
    EXPECT_EQ(s[4], "B");  // Индекс 5 эквивалентен 5 % 3 = 2
}

// Тесты для метода PRINT
TEST(StackTest, PRINT_NonEmptyStack) {
    Stack s;
    s.SPUSH("1");
    s.SPUSH("2");
    s.SPUSH("3");

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    s.PRINT();
    cout.rdbuf(old);

    EXPECT_EQ(buffer.str(), "3 2 1 - дно \n");
}

TEST(StackTest, PRINT_EmptyStack) {
    Stack s;

    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    s.PRINT();
    cout.rdbuf(old);

    EXPECT_EQ(buffer.str(), "Пустой стек\n");
}

TEST(StackTest, SLEN_currentlen)
{
    Stack s;
    s.SPUSH("1");
    EXPECT_EQ(s.SLEN(), 1);
}