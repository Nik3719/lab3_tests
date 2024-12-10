#include "Tools.h"

int mod(int a, int b)
{
    if (a < 0)
    {
        a = b - (-a);
    }
    return a % b;
}


void LoadInFile(int index, string value, string fileName, string NameStruct)
{
    ifstream readFile(fileName);
    json j;
    readFile >> j;
    readFile.close();
}

int ByteToInt(string str)
{
    int res = 0;
    for (unsigned char b : str)
    {
        res = (res << 8) + (b & 0xFF);
    }
    return res;
}

void createNewFile(string fileName, string Name)
{
    json j;
    j["Array"] = {};
    j["DoubleList"] = {};
    j["SingleList"] = {};
    j["Stack"] = {};
    j["Queue"] = {};
    j["HT"] = {};
    j["Tree"] = {};

    ofstream NewFile(fileName);
    NewFile << j.dump(4);
    NewFile.close();
}

bool fileExists(const string &filename)
{
    ifstream file(filename);
    bool res = file.good(); // ���������, ������� �� ������ ����
    if (res)
    {
        file.close();
    }
    return res;
}

bool ValidFile(const string &filename)
{
    ifstream file(filename);
    if (file.peek() == ifstream::traits_type::eof())
    {
        return false;
    }
    json j;
    file >> j;
    file.close();
    if (j.contains("Array") &&
        j.contains("DoubleList") &&
        j.contains("SingleList") &&
        j.contains("Stack") &&
        j.contains("Queue") &&
        j.contains("HT") &&
        j.contains("Tree"))
    {
        return true;
    }
    return false;
}

bool containsString(json jArray, string str)
{
    for (const auto &item : jArray)
    {
        if (item.is_string() && item.get<string>() == str)
        {
            return true; // ������� ������
        }
    }
    return false; // ������ �� �������
}

DL<string> split(string str)
{
    DL<string> res;
    size_t length = str.size();
    string buf = "";
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            res.LDPUSHT(buf);
            buf.clear();
        }
        else
        {
            buf += str[i];
        }
    }
    res.LDPUSHT(buf);
    return res;
}


// Освобождение памяти


string readFileContent(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        return "";
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}