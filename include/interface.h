#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include "Tools.h"
#include "Array.h"
#include "SingleList.h"
#include "DoubleList.h"
#include "queue.h"
#include "stack.h"
#include "Hash_Table.h"
#include "Tree.h"
#include "dict.h"


using namespace std;



int interface(int argc, const char *argv[])
{
Array files;
    filesystem::path dirPath = "/home/nik/Desktop/прога/lab3/c++/";

    if (filesystem::exists(dirPath) && filesystem::is_directory(dirPath))
    {
        for (const auto &entry : filesystem::directory_iterator(dirPath))
        {
            if (filesystem::is_regular_file(entry) && entry.path().extension() == ".json")
            {
                const string file = entry.path().string();
                files.MPUSH(file);
            }
        }
    }
    else
    {
        cerr << "Такого пути нет" << endl;
        exit(1);
    }

    if (argc <= 2)
    {
        cout << "Недостаточно аргументов\n";
        return 1;
    }

    string query, file;
    DoubleList args;
    for (int i = 0; i < argc; i++)
    {
        string str(argv[i]);
        if (str == "--file")
        {
            file = string(argv[i + 1]);
        }
        else if (str == "--query")
        {
            query = string(argv[i + 1]);
        }
        args.LDPUSHT(str);
    }
    string Name;
    bool isName = false;
    for (size_t i = 0; i < query.size(); i++)
    {
        if (isName && query[i] == ' ')
        {
            isName = false;
            break;
        }
        if (query[i] == ' ')
        {
            isName = true;
            continue;
        }
        if (isName)
        {
            Name += query[i];
        }
    }

    DL<string> querys = split(query);

    if (querys[0][0] == 'M') // Array
    {
        Array exm;
        string fileName = file;
        json j;
        if (!(fileExists(fileName) && ValidFile(fileName)))
        {
            createNewFile(fileName, Name);

            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["Array"][Name].is_null())
            {
                j["Array"][Name] = json::array();
            }
        }
        else
        {
            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["Array"][Name].is_null())
            {
                j["Array"][Name] = json::array();
            }
            else
            {
                for (const auto &item : j["Array"][Name])
                {
                    exm.MPUSH(item);
                }
            }

            ofstream FileWrite(fileName);
            FileWrite << j.dump(4);
            FileWrite.close();
        }

        switch (querys[0][1])
        {
        case 'P':
        {
            exm.MPUSH(querys[2]);
            break;
        }
        case 'I':
        {
            int index = atoi(querys[3].c_str());
            exm.MINSERT(querys[2], index);
            break;
        }
        case 'G':
        {
            int index = atoi(querys[2].c_str());
            cout << exm.MGET(index) << "\n";
            break;
        }
        case 'L':
        {
            cout << exm.MLEN() << "\n";
            break;
        }
        case 'D':
        {
            int index = atoi(querys[2].c_str());
            exm.MDEL(index);
            break;
        }
        case 'S':
        {
            int index = atoi(querys[3].c_str());
            exm.MSET(querys[2], index);
            break;
        }
        default:
            break;
        }

        exm.PRINT();

        j["Array"][Name].clear();
        for (int i = 0; i < exm.MLEN(); i++)
        {
            string elem = exm.MGET(i);
            if (elem == " Такого индекса нет!\n")
            {
                break;
            }
            j["Array"][Name].push_back(elem);
        }
        ofstream writeFile(fileName);
        writeFile << j.dump(4);
        writeFile.close();
    }
    //
    else if (querys[0][0] == 'L' && querys[0][1] == 'S') // SingleList
    {
        SingleList exm;

        string fileName = file;
        json j;
        if (!(fileExists(fileName) && ValidFile(fileName)))
        {
            createNewFile(fileName, Name);

            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["SingleList"][Name].is_null())
            {
                j["SingleList"][Name] = json::array();
            }
        }
        else
        {
            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["SingleList"][Name].is_null())
            {
                j["SingleList"][Name] = json::array();
            }
            else
            {
                for (const auto &item : j["SingleList"][Name])
                {
                    exm.LSPUSHT(item);
                }
            }

            ofstream FileWrite(fileName);
            FileWrite << j.dump(4);
            FileWrite.close();
        }

        if (querys[0] == "LSPUSHT")
        {
            exm.LSPUSHT(querys[2]);
        }
        else if (querys[0] == "LSPUSHH")
        {
            exm.LSPUSHH(querys[2]);
        }
        else if (querys[0] == "LSGET")
        {
            int index = atoi(querys[2].c_str());
            cout << exm.LSGET(index) << "\n";
        }
        else if (querys[0] == "LSDELH")
        {
            exm.LSDELH();
        }
        else if (querys[0] == "LSDELV")
        {
            string value = querys[2];
            exm.LSDELV(value);
        }
        else if (querys[0] == "LSINDEX")
        {
            string elem = querys[2];
            cout << exm.LISINDEX(elem) << '\n';
        }

        exm.PRINT();

        j["SingleList"][Name].clear();
        for (int i = 0; i < exm.LSLEN(); i++)
        {
            j["SingleList"][Name].push_back(exm.LSGET(i));
        }
        ofstream writeFile(fileName);
        writeFile << j.dump(4);
        writeFile.close();
    }
    else if (querys[0][0] == 'L' && querys[0][1] == 'D') // DoubleList
    {
        DoubleList exm;

        string fileName = file;
        json j;
        if (!(fileExists(fileName) && ValidFile(fileName)))
        {
            createNewFile(fileName, Name);

            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["DoubleList"][Name].is_null())
            {
                j["DoubleList"][Name] = json::array();
            }
        }
        else
        {
            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["DoubleList"][Name].is_null())
            {
                j["DoubleList"][Name] = json::array();
            }
            else
            {
                for (const auto &item : j["DoubleList"][Name])
                {
                    exm.LDPUSHT(item);
                }
            }

            ofstream FileWrite(fileName);
            FileWrite << j.dump(4);
            FileWrite.close();
        }

        if (querys[0] == "LDPUSHT")
        {
            exm.LDPUSHT(querys[2]);
        }
        else if (querys[0] == "LDPUSHH")
        {
            exm.LDPUSHH(querys[2]);
        }
        else if (querys[0] == "LDGET")
        {
            int index = atoi(querys[2].c_str());
            cout << exm.LDGET(index) << "\n";
        }
        else if (querys[0] == "LDDELH")
        {
            exm.LDDELH();
        }
        else if (querys[0] == "LDDELT")
        {
            exm.LDDELT();
        }
        else if (querys[0] == "LDDELV")
        {
            string value = querys[2];
            exm.LDDELV(value);
        }
        else if (querys[0] == "LDINDEX")
        {
            string elem = querys[2];
            cout << exm.LDISINDEX(elem) << '\n';
        }

        exm.PRINT();

        j["DoubleList"][Name].clear();
        for (int i = 0; i < exm.DLLEN(); i++)
        {
            j["DoubleList"][Name].push_back(exm.LDGET(i));
        }
        ofstream writeFile(fileName);
        writeFile << j.dump(4);
        writeFile.close();
    }
    else if (querys[0][0] == 'Q') // Queue
    {
        Queue exm;

        string fileName = file;
        json j;
        if (!(fileExists(fileName) && ValidFile(fileName)))
        {
            createNewFile(fileName, Name);

            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["Queue"][Name].is_null())
            {
                j["Queue"][Name] = json::array();
            }
        }
        else
        {
            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["Queue"][Name].is_null())
            {
                j["Queue"][Name] = json::array();
            }
            else
            {
                for (const auto &item : j["Queue"][Name])
                {
                    exm.QPUSH(item);
                }
            }

            ofstream FileWrite(fileName);
            FileWrite << j.dump(4);
            FileWrite.close();
        }

        if (querys[0] == "QPUSH")
        {
            exm.QPUSH(querys[2]);
        }
        else if (querys[0] == "QPOP")
        {
            exm.QPOP();
        }
        else if (querys[0] == "QGET")
        {
            int index = atoi(querys[2].c_str());
            cout << exm.QGET(index) << "\n";
        }

        exm.PRINT();

        j["Queue"][Name].clear();
        for (int i = 0; i < exm.QLEN(); i++)
        {
            j["Queue"][Name].push_back(exm.QGET(i));
        }
        ofstream writeFile(fileName);
        writeFile << j.dump(4);
        writeFile.close();
    }
    else if (querys[0][0] == 'S') // Stack
    {
        Stack exm;

        string fileName = file;
        json j;
        if (!(fileExists(fileName) && ValidFile(fileName)))
        {
            createNewFile(fileName, Name);

            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["Stack"][Name].is_null())
            {
                j["Stack"][Name] = json::array();
            }
        }
        else
        {
            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();
            DL<string> str;
            if (j["Stack"][Name].is_null())
            {
                j["Stack"][Name] = json::array();
            }
            else
            {
                for (const auto &item : j["Stack"][Name])
                {

                    exm.SPUSH(item);
                }
            }

            ofstream FileWrite(fileName);
            FileWrite << j.dump(4);
            FileWrite.close();
        }

        if (querys[0] == "SPUSH")
        {
            exm.SPUSH(querys[2]);
        }
        else if (querys[0] == "SPOP")
        {
            exm.SPOP();
        }
        else if (querys[0] == "SGET")
        {
            int index = atoi(querys[2].c_str());
            cout << exm.SGET(index) << "\n";
        }

        exm.PRINT();

        j["Stack"][Name].clear();
        for (int i = exm.SLEN() - 1; i >= 0; i--)
        {
            j["Stack"][Name].push_back(exm[i]);
        }
        ofstream writeFile(fileName);
        writeFile << j.dump(4);
        writeFile.close();
    }
    else if (querys[0][0] == 'T') // Tree
    {
        Tree exm;
        DL<DL<int>> myTree;
        string fileName = file;
        json j;
        if (!(fileExists(fileName) && ValidFile(fileName)))
        {
            createNewFile(fileName, Name);

            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["Tree"][Name].is_null())
            {
                j["Tree"][Name] = json::array();
            }
        }
        else
        {
            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["Tree"][Name].is_null())
            {
                j["Stack"][Name] = json::array();
            }
            else
            {
                for (const auto &item : j["Tree"][Name])
                {
                    DL<int> newElem;
                    for (const int &elem : item)
                    {
                        newElem.LDPUSHT(elem);
                        exm.TINSERT(elem);
                    }
                    myTree.LDPUSHT(newElem);
                }
            }

            ofstream FileWrite(fileName);
            FileWrite << j.dump(4);
            FileWrite.close();
        }
        switch (querys[0][2])
        {
        case 'N':
        {

            int newElem = atoi(querys[2].c_str());
            exm.TINSERT(newElem);
            myTree = exm.getLevels();
            break;
        }
        case 'S':
        {
            if (exm.TISCOMPLETE())
            {
                cout << "complete\n";
            }
            else
            {
                cout << "not complete\n";
            }
            break;
        }
        case 'E':
        {
            int newElem = atoi(querys[2].c_str());
            if (exm.TSEARCH(newElem))
            {
                cout << "presence\n";
            }
            else
            {
                cout << "not presence\n";
            }
            break;
        }
        default:
            break;
        }

        exm.PRINT();

        j["Tree"][Name].clear();
        for (int i = 0; i < myTree.len; i++)
        {
            DL<int> elem = myTree[i];
            json newElem = json::array();
            for (int j = 0; j < elem.len; j++)
            {
                newElem.push_back(elem[j]);
            }
            j["Tree"][Name].push_back(newElem);
        }
        ofstream writeFile(fileName);
        writeFile << j.dump(4);
        writeFile.close();
    }
    else if (querys[0][0] == 'H') // HT
    {
        Hash_Table exm;

        string fileName = file;
        json j;
        DL<string> listKey;
        if (!(fileExists(fileName) && ValidFile(fileName)))
        {
            createNewFile(fileName, Name);

            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["HT"][Name].is_null())
            {
                j["HT"][Name] = json::array();
            }
        }
        else
        {
            ifstream readFile(fileName);
            readFile >> j;
            readFile.close();

            if (j["HT"][Name].is_null())
            {
                j["HT"][Name] = json::array();
            }
            else
            {
                for (const auto &item : j["HT"][Name])
                {
                    for (const auto &[key, value] : item.items())
                    {
                        listKey.LDPUSHT(key);
                        exm.HSET(key, value);
                    }
                }
            }

            ofstream FileWrite(fileName);
            FileWrite << j.dump(4);
            FileWrite.close();
        }
        switch (querys[0][1])
        {
        case 'S':
        {
            string key = querys[2];
            if (listKey.LDISINDEX(key) == -1)
            {
                listKey.LDPUSHT(key);
            }
            string value = querys[3];
            exm.HSET(key, value);
            break;
        }
        case 'G':
        {
            string key = querys[2];
            cout << exm.HGET(key) << "\n";
            break;
        }
        case 'D':
        {
            string key = querys[2];
            listKey.LDDELV(key);
            exm.HDEL(key);
            break;
        }
        default:
            break;
        }

        exm.PRINT();

        j["HT"][Name].clear();
        for (int i = 0; i < listKey.len; i++)
        {
            string key = listKey.LDGET(i);
            if (key == "There isn't such elem\n")
            {
                break;
            }
            string value = exm.HGET(key);
            json elem;
            elem[key] = value;
            j["HT"][Name].push_back(elem);
        }
        ofstream writeFile(fileName);
        writeFile << j.dump(4);
        writeFile.close();
    }
    else
    {
        cout << "incorrect input\n";
    }
}