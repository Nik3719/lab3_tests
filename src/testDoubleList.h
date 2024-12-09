#include <gtest/gtest.h>
#include "DoubleList.h"

// Тестовый класс для DoubleList
class DoubleListTest : public ::testing::Test
{
protected:
    DoubleList list;

    void SetUp() override
    {
        list.LDPUSHT("A");
        list.LDPUSHT("B");
        list.LDPUSHT("C");
    }
    void clear()
    {
        list.LDDELH();
        list.LDDELH();
        list.LDDELH();
    }
};

// Тесты вставки элементов
TEST_F(DoubleListTest, PushHead)
{
    // Очищаем список перед тестом
    clear(); // Предполагаем, что этот метод корректно очищает список
    // Добавляем элемент в начало
    list.LDPUSHH("1");
    EXPECT_EQ(list[0], "1"); // Проверяем, что первый элемент это "1"

    // Добавляем еще один элемент в начало
    list.LDPUSHH("D");
    EXPECT_EQ(list[0], "D"); // Проверяем, что теперь первый элемент это "D"
    EXPECT_EQ(list[1], "1"); // Проверяем, что второй элемент это "1"
}

TEST_F(DoubleListTest, PushTail)
{
    list.LDPUSHT("D");
    EXPECT_EQ(list.LDGET(3), "D");
}

// Тесты удаления элементов
TEST_F(DoubleListTest, DeleteHead)
{
    list.LDDELH();
    EXPECT_EQ(list.LDGET(0), "B");
}

TEST_F(DoubleListTest, DeleteHeadEmptyList)
{
    clear();
    EXPECT_EQ(list.LDDELH(), "list empty\n");
}

TEST_F(DoubleListTest, DeleteTail)
{
    list.LDDELT();
    EXPECT_EQ(list.LDGET(1), "B");
}

TEST_F(DoubleListTest, DeleteTailOneElem)
{
    clear();
    list.LDPUSHT("1");
    list.LDDELT();
    EXPECT_EQ(list.DLLEN(), 0);
}

TEST_F(DoubleListTest, DeleteTailEmpList)
{
    clear();
    testing::internal::CaptureStdout();
    list.LDDELT();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "list empty\n");
}

TEST_F(DoubleListTest, DeleteByValueExists)
{
    list.LDDELV("B");
    EXPECT_EQ(list.LDISINDEX("B"), -1);
}

TEST_F(DoubleListTest, DeleteByValueNotFound)
{
    EXPECT_EQ(list.LDDELV("X"), "Element not found.\n");
}

TEST_F(DoubleListTest, DeleteByValueOneElemInList)
{
    clear();
    list.LDPUSHT("1");
    list.LDDELV("1");
    EXPECT_EQ(list.DLLEN(), 0);
}

TEST_F(DoubleListTest, DeleteByValueHead)
{
    clear();
    list.LDPUSHT("1");
    list.LDPUSHT("2");
    list.LDDELV("1");
    EXPECT_EQ(list[0], "2");
}

TEST_F(DoubleListTest, DeleteByValueTail)
{
    clear();
    list.LDPUSHT("1");
    list.LDPUSHT("2");
    list.LDDELV("2");
    EXPECT_EQ(list[0], "1");
}

TEST_F(DoubleListTest, DeleteByValueEmp)
{
    clear();
    EXPECT_EQ(list.LDDELV("1"), "List is empty\n");
}

// Тесты получения индексов и элементов
TEST_F(DoubleListTest, GetIndex)
{
    EXPECT_EQ(list.LDISINDEX("B"), 1);
    EXPECT_EQ(list.LDISINDEX("X"), -1);
}

TEST_F(DoubleListTest, GetByIndexValid)
{
    EXPECT_EQ(list.LDGET(0), "A");
    EXPECT_EQ(list.LDGET(2), "C");
}

TEST_F(DoubleListTest, GetByIndexInvalid)
{
    EXPECT_THROW(list.LDGET(10), std::out_of_range);
}

// Тесты перегрузки оператора []
TEST_F(DoubleListTest, OperatorAccessValid)
{
    EXPECT_EQ(list[0], "A");
    EXPECT_EQ(list[1], "B");
    EXPECT_EQ(list[2], "C");
}

TEST_F(DoubleListTest, OperatorAccessNegativeIndex)
{
    EXPECT_EQ(list[-1], "C"); // Обход с конца
    EXPECT_EQ(list[-2], "B");
}

TEST_F(DoubleListTest, OperatorAccessOutOfRange)
{
    EXPECT_THROW(list[10], std::out_of_range);
}

// Тесты на печать списка
TEST_F(DoubleListTest, PrintList)
{
    // Захват вывода в stdout
    testing::internal::CaptureStdout();
    clear();
    EXPECT_ANY_THROW(list.PRINT()); // Ожидаем исключение, если список пуст
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
    list.LDPUSHT("A");
    list.LDPUSHT("B");
    list.LDPUSHT("C");
    testing::internal::CaptureStdout();
    list.PRINT();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A B C \n");
}
