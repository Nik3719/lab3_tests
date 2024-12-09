#pragma once
#include <gtest/gtest.h>
#include "SingleList.h"

class SingleListTest : public ::testing::Test
{
protected:
    SingleList list;
};

// **Тест на добавление элементов в начало**
TEST_F(SingleListTest, PushHead)
{
    list.LSPUSHH("A");
    list.LSPUSHH("B");
    list.LSPUSHH("C");

    EXPECT_EQ(list.LSGET(0), "C");
    EXPECT_EQ(list.LSGET(1), "B");
    EXPECT_EQ(list.LSGET(2), "A");
}

// **Тест на добавление элементов в конец**
TEST_F(SingleListTest, PushTail)
{

    list.LSPUSHT("1");
    list.LSPUSHT("2");
    list.LSPUSHT("3");

    EXPECT_EQ(list.LSGET(0), "1");
    EXPECT_EQ(list.LSGET(1), "2");
    EXPECT_EQ(list.LSGET(2), "3");
}

// **Тест на удаление первого элемента**
TEST_F(SingleListTest, DeleteHead)
{

    EXPECT_EQ(list.LSDELH(), "list is empty\n");

    list.LSPUSHT("X");
    list.LSPUSHT("Y");
    list.LSDELH(); // Удаляем "X"

    EXPECT_EQ(list.LSGET(0), "Y");
}

// **Тест на удаление по значению**
TEST_F(SingleListTest, DeleteByValue)
{

    EXPECT_EQ(list.LSDELV("1"), "list is empty\n");

    list.LSPUSHT("1");
    list.LSPUSHT("2");
    list.LSPUSHT("3");

    list.LSDELV("2"); // Удаляем "2"

    EXPECT_EQ(list.LSGET(0), "1");
    EXPECT_EQ(list.LSGET(1), "3");

    EXPECT_EQ(list.LSDELV("4"), "There is no such elem\n"); // Удаляем несуществующий элемент
}

// test for del elem value from head
TEST_F(SingleListTest, DelValOnHead)
{
    list.LSPUSHT("1");

    EXPECT_EQ(list.LSDELV("1"), "0");
    EXPECT_EQ(list.LSLEN(), 0);
}
// **Тест на получение элемента по индексу**
TEST_F(SingleListTest, GetElementByIndex)
{
    list.LSPUSHT("Apple");
    list.LSPUSHT("Banana");
    list.LSPUSHT("Cherry");

    EXPECT_EQ(list.LSGET(0), "Apple");
    EXPECT_EQ(list.LSGET(1), "Banana");
    EXPECT_EQ(list.LSGET(2), "Cherry");
    EXPECT_EQ(list.LSGET(3), "Такого индекса нет!");
}

// **Тест на поиск индекса элемента**
TEST_F(SingleListTest, FindIndex)
{
    list.LSPUSHT("Dog");
    list.LSPUSHT("Cat");
    list.LSPUSHT("Bird");

    EXPECT_EQ(list.LISINDEX("Dog"), 0);
    EXPECT_EQ(list.LISINDEX("Cat"), 1);
    EXPECT_EQ(list.LISINDEX("Bird"), 2);
    EXPECT_EQ(list.LISINDEX("Fish"), -1); // Элемент отсутствует
}

// **Тест оператора индексации**
TEST_F(SingleListTest, OperatorIndex)
{
    list.LSPUSHT("One");
    list.LSPUSHT("Two");
    list.LSPUSHT("Three");

    EXPECT_EQ(list[0], "One");
    EXPECT_EQ(list[1], "Two");
    EXPECT_EQ(list[2], "Three");

    list[1] = "NewTwo"; // Изменяем второй элемент
    EXPECT_EQ(list[1], "NewTwo");
}

// **Тест на корректный вывод списка**
TEST_F(SingleListTest, PrintCheck)
{
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

    list.PRINT();
    EXPECT_EQ(buffer.str(), "\n"); // Пустой список

    list.LSPUSHT("10");
    list.LSPUSHT("20");
    list.LSPUSHT("30");
    buffer.str("");
    list.PRINT();

    std::cout.rdbuf(old); // Восстановление стандартного вывода

    EXPECT_EQ(buffer.str(), "10 20 30 \n");
}
