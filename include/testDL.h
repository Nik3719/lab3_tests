#include <gtest/gtest.h>
#include "DL.h"  // Подключаем ваш заголовочный файл с классом DL

// Тестовый случай для удаления элемента из пустого списка
TEST(DLTest, RemoveFromEmptyList) {
    DL<int> list;
    list.LDDELV(10);
    EXPECT_EQ(list.len, 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

// Тестовый случай для удаления единственного элемента из списка
TEST(DLTest, RemoveOnlyElement) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDDELV(10);
    EXPECT_EQ(list.len, 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

// Тестовый случай для удаления элемента из начала списка
TEST(DLTest, RemoveFromHead) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDPUSHT(20);
    list.LDPUSHT(30);
    list.LDDELV(10);
    EXPECT_EQ(list.len, 2);
    EXPECT_EQ(list.head->data, 20);
    EXPECT_EQ(list.tail->data, 30);
}

// Тестовый случай для удаления элемента из середины списка
TEST(DLTest, RemoveFromMiddle) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDPUSHT(20);
    list.LDPUSHT(30);
    list.LDDELV(20);
    EXPECT_EQ(list.len, 2);
    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.tail->data, 30);
}

// Тестовый случай для удаления элемента из конца списка
TEST(DLTest, RemoveFromTail) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDPUSHT(20);
    list.LDPUSHT(30);
    list.LDDELV(30);
    EXPECT_EQ(list.len, 2);
    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.tail->data, 20);
}

// Тестовый случай для попытки удаления элемента, которого нет в списке
TEST(DLTest, RemoveNonExistentElement) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDPUSHT(20);
    list.LDDELV(30);
    EXPECT_EQ(list.len, 2);
    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.tail->data, 20);
}

// Тестовый случай для удаления всех элементов из списка
TEST(DLTest, RemoveAllElements) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDPUSHT(20);
    list.LDPUSHT(30);
    list.LDDELV(10);
    list.LDDELV(20);
    list.LDDELV(30);
    EXPECT_EQ(list.len, 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

// Тестовый случай для удаления элемента из списка с одинаковыми элементами
TEST(DLTest, RemoveDuplicateElements) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDPUSHT(10);
    list.LDPUSHT(10);
    list.LDDELV(10);
    EXPECT_EQ(list.len, 2);
    EXPECT_EQ(list.head->data, 10);
    EXPECT_EQ(list.tail->data, 10);
}


// Тестовый случай для удаления элемента из пустого списка
TEST(DLTest, RemoveFromHeadEmptyList) {
    DL<int> list;
    list.LDDELH();
    EXPECT_EQ(list.len, 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

// Тестовый случай для удаления единственного элемента из списка
TEST(DLTest, RemoveFromHeadOnlyElement) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDDELH();
    EXPECT_EQ(list.len, 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

// Тестовый случай для удаления элемента из начала списка с несколькими элементами
TEST(DLTest, RemoveFromHeadMultipleElements) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDPUSHT(20);
    list.LDPUSHT(30);
    list.LDDELH();
    EXPECT_EQ(list.len, 2);
    EXPECT_EQ(list.head->data, 20);
    EXPECT_EQ(list.tail->data, 30);
}

// Тестовый случай для удаления элемента из списка, где head и tail указывают на один элемент
TEST(DLTest, RemoveFromHeadSingleElementList) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDDELH();
    EXPECT_EQ(list.len, 0);
    EXPECT_EQ(list.head, nullptr);
    EXPECT_EQ(list.tail, nullptr);
}

// Тестовый случай для удаления элемента из списка с несколькими элементами (проверка связей)
TEST(DLTest, RemoveFromHeadCheckLinks) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDPUSHT(20);
    list.LDPUSHT(30);
    list.LDDELH();
    EXPECT_EQ(list.len, 2);
    EXPECT_EQ(list.head->data, 20);
    EXPECT_EQ(list.head->prev, nullptr); // Проверяем, что предыдущий элемент head равен nullptr
    EXPECT_EQ(list.tail->data, 30);
}

// Тестовый случай для удаления элемента из списка с несколькими элементами (несколько удалений подряд)
TEST(DLTest, RemoveFromHeadMultipleDeletions) {
    DL<int> list;
    list.LDPUSHT(10);
    list.LDPUSHT(20);
    list.LDPUSHT(30);
    list.LDDELH();
    list.LDDELH();
    EXPECT_EQ(list.len, 1);
    EXPECT_EQ(list.head->data, 30);
    EXPECT_EQ(list.tail->data, 30);
    EXPECT_EQ(list.head, list.tail); // Проверяем, что head и tail указывают на один элемент
}