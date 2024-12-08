#include "queue.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(QueueTest, PushAndPop)
{
    Queue q;

    q.QPUSH("A");
    q.QPUSH("B");
    q.QPUSH("C");

    EXPECT_EQ(q.QPOP(), "A");
    EXPECT_EQ(q.QPOP(), "B");
    EXPECT_EQ(q.QPOP(), "C");
    EXPECT_EQ(q.QPOP(), "Queue is empty\n");
}

TEST(QueueTest, PopFromEmptyQueue)
{
    Queue q;
    EXPECT_EQ(q.QPOP(), "Queue is empty\n");
}

TEST(QueueTest, GetElementByIndex)
{
    Queue q;

    EXPECT_EQ(q.QGET(1), "Очередь пуста");

    q.QPUSH("X");
    q.QPUSH("Y");
    q.QPUSH("Z");

    EXPECT_EQ(q.QGET(0), "X");
    EXPECT_EQ(q.QGET(1), "Y");
    EXPECT_EQ(q.QGET(2), "Z");

    // Проверка на некорректные индексы
    EXPECT_EQ(q.QGET(-1), "Index out of range.");
    EXPECT_EQ(q.QGET(5), "Index out of range.");
}

TEST(QueueTest, IsEmptyCheck)
{
    Queue q;
    EXPECT_TRUE(q.isEmpty());
    q.QPUSH("Test");
    EXPECT_FALSE(q.isEmpty());
}

TEST(QueueTest, PrintCheck)
{
    Queue q;

    // Перехват стандартного вывода
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    // Проверка на пустой очередь
    q.PRINT();
    std::string output = buffer.str();
    EXPECT_EQ(output, "Queue is empty\n");

    // Очистить буфер
    buffer.str("");
    buffer.clear();

    // Добавить элементы и снова проверить
    q.QPUSH("1");
    q.QPUSH("2");
    q.QPUSH("3");
    q.PRINT();

    std::cout.rdbuf(old);  // Восстановить стандартный вывод

    EXPECT_EQ(buffer.str(), "3 2 1  - Первый добавленный удалённ будет первым\n");
}


TEST(QueueTest, DestructorCheck)
{
    Queue *q = new Queue();
    q->QPUSH("A");
    q->QPUSH("B");
    delete q; // Проверка на корректное освобождение памяти
}

TEST(QueueTest, QLEN)
{
    Queue q;
    q.QPUSH("1");
    int len = q.QLEN();
    EXPECT_EQ(len, 1);
}
