#include <fstream>
#include "Array.h"
#include "SingleList.h"
#include "DoubleList.h"
#include "queue.h"
#include "stack.h"
#include "Hash_Table.h"
#include "Tree.h"

void serialize(const Array &array, const string &filename)
{
    ofstream out(filename, ios::binary);
    if (out.is_open())
    {
        // Записать количество элементов
        int len = array.MLEN();
        out.write(reinterpret_cast<const char *>(&len), sizeof(len));

        // Записать каждый элемент
        for (int i = 0; i < len; ++i)
        {
            string str = array.MGET(i);
            size_t str_len = str.size();
            out.write(reinterpret_cast<const char *>(&str_len), sizeof(str_len)); // Записать длину строки
            out.write(str.c_str(), str_len);                                      // Записать саму строку
        }
        out.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для записи!" << endl;
    }
}

// Функция для бинарной десериализации
void deserialize(Array &array, const string &filename)
{
    ifstream in(filename, ios::binary);
    if (in.is_open())
    {
        // Прочитать количество элементов
        int len;
        in.read(reinterpret_cast<char *>(&len), sizeof(len));

        // Создать массив с нужным количеством элементов
        for (int i = 0; i < len; ++i)
        {
            size_t str_len;
            in.read(reinterpret_cast<char *>(&str_len), sizeof(str_len)); // Прочитать длину строки
            string str(str_len, '\0');
            in.read(&str[0], str_len); // Прочитать саму строку
            array.MPUSH(str);          // Добавить строку в массив
        }
        in.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для чтения!" << endl;
    }
}

// Функция для бинарной сериализации
void serialize(SingleList &list, const string &filename)
{
    ofstream out(filename, ios::binary);
    if (out.is_open())
    {
        int len = list.LSLEN();
        // Записать количество элементов
        out.write(reinterpret_cast<const char *>(&len), sizeof(len));

        // Записать каждый элемент списка

        for (size_t i = 0; i < len; i++)
        {
            size_t str_len = list[i].size();
            out.write(reinterpret_cast<const char *>(&str_len), sizeof(str_len)); // Записать длину строки
            out.write(list[i].c_str(), str_len);                                  // Записать строку
        }

        out.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для записи!" << endl;
    }
}

// Функция для бинарной десериализации
void deserialize(SingleList &list, const string &filename)
{
    ifstream in(filename, ios::binary);
    if (in.is_open())
    {
        // Прочитать количество элементов
        int len;
        in.read(reinterpret_cast<char *>(&len), sizeof(int));

        // Создать список из элементов
        for (int i = 0; i < len; ++i)
        {
            size_t str_len;
            in.read(reinterpret_cast<char *>(&str_len), sizeof(str_len)); // Прочитать длину строки
            string str(str_len, '\0');
            in.read(&str[0], str_len); // Прочитать саму строку
            list.LSPUSHT(str);         // Добавить строку в список
        }

        in.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для чтения!" << endl;
    }
}

// Функция для бинарной сериализации
void serialize(Queue &queue, const string &filename)
{
    ofstream out(filename, ios::binary);
    if (out.is_open())
    {
        int len = queue.QLEN();
        // Записать количество элементов в очереди
        out.write(reinterpret_cast<const char *>(&len), sizeof(int));

        // Записать элементы очереди
        for (size_t i = 0; i < len; i++)
        {
            size_t str_len = queue.QGET(i).size();
            out.write(reinterpret_cast<const char *>(&str_len), sizeof(str_len)); // Записать длину строки
            out.write(queue.QGET(i).c_str(), str_len);                            // Записать строку
        }

        out.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для записи!" << endl;
    }
}

// Функция для бинарной десериализации
void deserialize(Queue &queue, const string &filename)
{
    ifstream in(filename, ios::binary);
    if (in.is_open())
    {
        // Прочитать количество элементов
        int len;
        in.read(reinterpret_cast<char *>(&len), sizeof(int));

        // Создать очередь из элементов
        for (int i = 0; i < len; ++i)
        {
            size_t str_len;
            in.read(reinterpret_cast<char *>(&str_len), sizeof(str_len)); // Прочитать длину строки
            string str(str_len, '\0');
            in.read(&str[0], str_len); // Прочитать саму строку
            queue.QPUSH(str);          // Добавить строку в очередь
        }

        in.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для чтения!" << endl;
    }
}

// Функция для бинарной сериализации
void serialize(Stack &stack, const string &filename)
{
    ofstream out(filename, ios::binary);
    if (out.is_open())
    {
        int len = stack.SLEN();
        // Записать количество элементов в стеке
        out.write(reinterpret_cast<const char *>(&len), sizeof(int));

        for (size_t i = 0; i < len; i++)
        {
            size_t str_len = stack.SGET(i).size();
            out.write(reinterpret_cast<const char *>(&str_len), sizeof(str_len)); // Записать длину строки
            out.write(stack.SGET(i).c_str(), str_len);                            // Записать строку
        }

        out.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для записи!" << endl;
    }
}

// Функция для бинарной десериализации
void deserialize(Stack &stack, const string &filename)
{
    ifstream in(filename, ios::binary);
    if (in.is_open())
    {
        // Прочитать количество элементов
        int len;
        in.read(reinterpret_cast<char *>(&len), sizeof(int));

        // Восстановить стек из элементов
        for (int i = 0; i < len; ++i)
        {
            size_t str_len;
            in.read(reinterpret_cast<char *>(&str_len), sizeof(str_len)); // Прочитать длину строки
            string str(str_len, '\0');
            in.read(&str[0], str_len); // Прочитать саму строку
            stack.SPUSH(str);          // Добавить строку в стек
        }

        in.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для чтения!" << endl;
    }
}

void serialize(DoubleList &list, const string &filename)
{
    ofstream out(filename, ios::binary);
    if (out.is_open())
    {
        int len = list.DLLEN();
        // Записать количество элементов
        out.write(reinterpret_cast<const char *>(&len), sizeof(len));

        // Записать каждый элемент списка

        for (size_t i = 0; i < len; i++)
        {
            size_t str_len = list[i].size();
            out.write(reinterpret_cast<const char *>(&str_len), sizeof(str_len)); // Записать длину строки
            out.write(list[i].c_str(), str_len);                                  // Записать строку
        }

        out.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для записи!" << endl;
    }
}

// Функция для бинарной десериализации
void deserialize(DoubleList &list, const string &filename)
{
    ifstream in(filename, ios::binary);
    if (in.is_open())
    {
        // Прочитать количество элементов
        int len;
        in.read(reinterpret_cast<char *>(&len), sizeof(int));

        // Создать список из элементов
        for (int i = 0; i < len; ++i)
        {
            size_t str_len;
            in.read(reinterpret_cast<char *>(&str_len), sizeof(str_len)); // Прочитать длину строки
            string str(str_len, '\0');
            in.read(&str[0], str_len); // Прочитать саму строку
            list.LDPUSHT(str);         // Добавить строку в список
        }

        in.close();
    }
    else
    {
        cerr << "Не удалось открыть файл для чтения!" << endl;
    }
}



