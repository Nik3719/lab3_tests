#include <gtest/gtest.h>
#include "Hash_Table.h"

TEST(HashTableTest, HSET_HGET)
{
    Hash_Table ht(5); // создаём хеш-таблицу с размером 5

    // Проверка добавления и получения значений
    ht.HSET("key1", "value1");
    EXPECT_EQ(ht.HGET("key1"), "value1"); // Проверяем, что значение правильно сохранено

    ht.HSET("key2", "value2");
    EXPECT_EQ(ht.HGET("key2"), "value2"); // Проверяем второе значение

    ht.HSET("key1", "new_value1");
    EXPECT_EQ(ht.HGET("key1"), "new_value1"); // Проверяем обновление значения для существующего ключа
}

TEST(HashTableTest, HDEL)
{
    Hash_Table ht(5); // создаём хеш-таблицу с размером 5

    // Добавляем несколько значений
    ht.HSET("key1", "value1");
    ht.HSET("key2", "value2");

    // Проверка удаления
    std::string result = ht.HDEL("key1");
    EXPECT_EQ(result, "value1");                                         // Проверяем, что удалено правильное значение
    EXPECT_EQ(ht.HGET("key1"), "There is not such key in this table\n"); // Проверяем, что ключ больше не существует

    // Проверка удаления несуществующего ключа
    result = ht.HDEL("key3");
    EXPECT_EQ(result, "There is not such key in this table\n");
}

TEST(HashTableTest, Resize)
{
    Hash_Table ht(2); // создаём хеш-таблицу с размером 2

    // Добавляем элементы, чтобы вызвать увеличение размера
    ht.HSET("key1", "value1");
    ht.HSET("key2", "value2");
    ht.HSET("key3", "value3"); // Это должно вызвать ресайз

    // Проверка, что элементы не потеряны после ресайза
    EXPECT_EQ(ht.HGET("key1"), "value1");
    EXPECT_EQ(ht.HGET("key2"), "value2");
    EXPECT_EQ(ht.HGET("key3"), "value3");
}

TEST(HashTableTest, PRINT)
{
    Hash_Table ht(5);

    ht.HSET("key1", "value1");
    ht.HSET("key2", "value2");

    // Захватываем вывод в стандартный поток
    testing::internal::CaptureStdout();
    ht.PRINT();
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем, что вывод содержит правильные данные
    EXPECT_TRUE(output.find("key1:value1") != std::string::npos);
    EXPECT_TRUE(output.find("key2:value2") != std::string::npos);
}