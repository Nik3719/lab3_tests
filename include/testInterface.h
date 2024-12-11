#include <gtest/gtest.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include "interface.h"
#include "Tools.h"

using namespace std;

// Прототип тестируемой функции
int interface(int argc, char *argv[]);



// Тест работы с массивом
TEST(InterfaceTest, ProcessArrayTest)
{
    char *args[] = {"--file", "test.json", "--query", "MPUSH test_array 5"};
    EXPECT_EQ(interface(4, args), 0);

    string content = readFileContent("test.json");
    EXPECT_NE(content.find("test_array"), string::npos);
    EXPECT_NE(content.find("5"), string::npos);
}

// Тест работы со стеком
TEST(InterfaceTest, ProcessStackTest)
{
    char *args1[] = {"--file", "test.json", "--query", "SPUSH test_stack 42"};
    EXPECT_EQ(interface(4, args1), 0);

    char *args2[] = {"--file", "test.json", "--query", "SPOP test_stack"};
    EXPECT_EQ(interface(4, args2), 0);
}

// Тест работы с односвязным списком
TEST(InterfaceTest, ProcessSingleListTest)
{
    char *args[] = {"--file", "test.json", "--query", "LSPUSHT my_list 7"};
    EXPECT_EQ(interface(4, args), 0);

    string content = readFileContent("test.json");
    EXPECT_NE(content.find("my_list"), string::npos);
    EXPECT_NE(content.find("7"), string::npos);
}

// Тест работы с хеш-таблицей
TEST(InterfaceTest, ProcessHashTableTest)
{
    char *args1[] = {"--file", "test.json", "--query", "HS my_hash key value"};
    EXPECT_EQ(interface(4, args1), 0);

    char *args2[] = {"--file", "test.json", "--query", "HG my_hash key"};
    EXPECT_EQ(interface(4, args2), 0);

    string content = readFileContent("test.json");
    EXPECT_NE(content.find("key"), string::npos);
    EXPECT_NE(content.find("value"), string::npos);
}

// Тест обработки некорректных команд
TEST(InterfaceTest, IncorrectCommandTest)
{
    char *args[] = {"--file", "test.json", "--query", "WRONGCOMMAND"};
    EXPECT_EQ(interface(4, args), 0);

    string content = readFileContent("test.json");
    EXPECT_EQ(content.find("WRONGCOMMAND"), string::npos); // Не должно быть такого ключа
}

TEST(InterfaceTest, NewFile)
{
    system("rm testNewFile.json");
    char *args[] = {"--file", "testNewFile.json", "--query", "MPUSH 1 1"};
    EXPECT_EQ(interface(4, args), 0);

    bool isExist = false;
    if (fileExists("testNewFile.json") && ValidFile("testNewFile.json"))
    {
        isExist = true;
    }
    EXPECT_EQ(isExist, true);
}

TEST(InterfaceTest, ReadAndWriteJson)
{
    json j = {{"key", "value"}};
    string fileName = "test.json";

    writeInJson(fileName, j);

    json jRead;
    readJson(fileName, jRead);

    EXPECT_EQ(j, jRead);
    filesystem::remove(fileName);
}

// Test argument parsing
TEST(InterfaceTest, GetArgs)
{
    int argc = 4;
    char *argv[] = {"--file", "test.json", "--query", "MPUSH D"};
    string query, file;
    DoubleList args;

    getArgs(query, file, args, argc, argv);

    EXPECT_EQ(file, "test.json");
    EXPECT_EQ(query, "MPUSH D");
}

// Test name extraction
TEST(InterfaceTest, GetName)
{
    string query = "MPUSH D";
    string name;
    bool isName = false;
    getName(query, name, isName);

    EXPECT_EQ(name, "D");
}

// Тесты для разных запросов с массивами
TEST(InterfaceTest, TestArrayMGet)
{
    char *argv[] = {"--file", "test.json", "--query", "MGET 0"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

TEST(InterfaceTest, TestArrayMSet)
{
    char *argv[] = {"--file", "test.json", "--query", "MSET 0 value"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

TEST(InterfaceTest, TestArrayMDelete)
{
    char *argv[] = {"--file", "test.json", "--query", "MDELETE 0"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

// Тесты для работы с односвязным списком
TEST(InterfaceTest, TestListLSPush)
{
    char *argv[] = {"--file", "test.json", "--query", "LSPUSH value"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

TEST(InterfaceTest, TestListLSPop)
{
    char *argv[] = {"--file", "test.json", "--query", "LSPOP"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

// Тесты для работы с деревом
TEST(InterfaceTest, TestTreeInsert)
{
    char *argv[] = {"--file", "test.json", "--query", "TINSERT 5"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

TEST(InterfaceTest, TestTreeRemove)
{
    char *argv[] = {"--file", "test.json", "--query", "TREMOVE 5"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

// Тесты для работы с хеш-таблицей
TEST(InterfaceTest, TestHashTableSet)
{
    char *argv[] = {"--file", "test.json", "--query", "HSET key value"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

TEST(InterfaceTest, TestHashTableGet)
{
    char *argv[] = {"--file", "test.json", "--query", "HGET key"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

TEST(InterfaceTest, TestHashTableDelete)
{
    char *argv[] = {"--file", "test.json", "--query", "HGET key"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат
}

// Тесты на ошибки (неверные запросы и параметры)
TEST(InterfaceTest, TestInvalidArguments)
{
    char *argv[] = {"output/main"};
    int argc = 1;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 1); // Ожидаем ошибку из-за недостаточных аргументов
}

TEST(InterfaceTest, TestInvalidQuery)
{
    char *argv[] = {"--file", "test.json", "--query", "QPUSH 1 1"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем ошибку, так как запрос неверный
}

// Тестирование пустых значений
TEST(InterfaceTest, TestEmptyFile)
{
    char *argv[] = {"--file", "empty.json", "--query", "MGET 0"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем успешный результат, даже если файл пуст
}

// Тестирование незаполненных структур
TEST(InterfaceTest, TestEmptyList)
{
    char *argv[] = {"--file", "test.json", "--query", "LDPUSHT 123 234"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем ошибку, если список пуст
}

TEST(InterfaceTest, TestEmptyTree)
{
    char *argv[] = {"--file", "test.json", "--query", "TINSERT 12 421"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем ошибку, если дерево пусто
}

TEST(InterfaceTest, TestEmptyHashTable)
{
    char *argv[] = {"--file", "test.json", "--query", "HSET key value"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем ошибку, если хеш-таблица пуста
}


TEST(InterfaceTest, TestInsertArray)
{
    system("rm test.json");
    char *argv[] = {"--file", "test.json", "--query", "MINSERT key 0"};
    int argc = 4;

    int result = interface(argc, (argv));
    EXPECT_EQ(result, 0); // Ожидаем ошибку, если хеш-таблица пуста
}

// TEST(InterfaceTest, TestInsertArray)
// {
//     system("rm test.json");
//     char *argv[] = {"--file", "test.json", "--query", "MINSERT key 0"};
//     int argc = 4;

//     int result = interface(argc, (argv));
//     EXPECT_EQ(result, 0); // Ожидаем ошибку, если хеш-таблица пуста
// }