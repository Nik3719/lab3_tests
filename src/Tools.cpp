#include"Tools.h"

int mod(int a, int b)
{
    if (a < 0)
    {
        a = b - (-a);
    }
    return a % b;
}


string PlusOne(string& num)
{
    int len = num.size();
    int countLoop = 0;
    for (size_t i = len - 1; i >= 0; i--)
    {
        if (num[i] < '9')
        {
            num = num.substr(0, i) + char(num[i] + 1);
            string countNull = "";
            for (int j = 0; j < countLoop; j++)
            {
                countNull += '0';
            }
            num = num + countNull;
            return num;
        }
        countLoop++;
    }
}
void LoadInFile(int index, string value, string fileName, string NameStruct)
{
    ifstream readFile(fileName);
    json j;
    readFile >> j;
    readFile.close();


}
//void LoadInFile(int index, string value,string fileName)
//{
//    ifstream file(fileName);
//    string data;
//    while (!file.eof())
//    {
//        getline(file, data);
//    }
//    file.close();
//    if (index == -1)
//    {
//        data = value + " " + data;
//        ofstream fwrt(fileName);
//        fwrt << data;
//        fwrt.close();
//        return;
//    }
//    int counter = 0;
//    int len = data.size();
//    bool alreadyReplace = false;
//    for (int i = 0; i < len; i++)
//    {
//        if (data[i] != ' ')
//        {
//            counter++;
//            if (counter - 1 == index)
//            {
//                int indexStartElem = i;
//                while (data[i] != ' ' && i < len) i++;
//                int indexEndElem = i;
//                string newData = "";
//                bool alreadyVisited = false;
//                for (int j = 0; j < len; j++)
//                {
//                    if (!(j < indexStartElem) && !alreadyVisited)
//                    {
//                        newData += value;// +' '
//                        if (value == "")
//                        {
//                            while (data[j++] != ' ' && j < len);
//                            if (j!=len) j--;
//                            if (!newData.empty())
//                            {
//                                newData.pop_back();
//                            }
//                            
//                       
//                        }
//                        //while (j != indexEndElem) j++;
//                        alreadyVisited = true;
//                        continue;
//                    }
//                    newData += data[j];
//                }
//                ofstream fwrite(fileName);
//                fwrite << newData;
//                fwrite.close();
//                alreadyReplace = true;
//                break;
//            }
//            while (data[i] != ' ' &&  i<len) i++;
//        }
//    }
//    if (!alreadyReplace)
//    {
//        if (index == 0)
//        {
//            data += value;
//        }
//        else
//        {
//            data += " " + value;
//        }
//
//        ofstream fwr(fileName);
//        fwr << data;
//        fwr.close();
//    }
//}

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


bool fileExists(const string& filename) 
{
    ifstream file(filename);
    bool res = file.good(); // Проверяем, успешно ли открыт файл
    if (res)
    {
        file.close();
    }
    return res;
}

bool ValidFile(const string& filename)
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
    for (const auto& item : jArray) 
    {
        if (item.is_string() && item.get<string>() == str) 
        {
            return true; // Найдена строка
        }
    }
    return false; // Строка не найдена
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

int64_t dg(int64_t base, int64_t exponent) 
{
    long long result = 1;
    while (exponent > 0) {
        // Если exponent нечетный, умножаем результат на base
        if (exponent % 2 == 1) {
            result *= base;
        }
        // Умножаем base на себя
        base *= base;
        // Делим exponent на 2
        exponent /= 2;
    }
    return result;
}