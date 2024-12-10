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
#include "interface.h"

#include <gtest/gtest.h>
#include "testArray.h"
#include "testStack.h"
#include "testQueue.h"
#include "testTree.h"
#include "testSingleList.h"
#include "testDoubleList.h"
#include "testHash_Table.h"
#include "testInterface.h"

int globalArgc;
char **globalArgv;

char *arg[] = {"--file", "11.json", "--query", "SPUSH 1 3"};

int main(int argc, char *argv[])
{
    globalArgc = argc;
    globalArgv = argv;
    // argc = 4;
    // argv = arg;

    // filesystem::path dirPath = "/home/nik/Desktop/прога/lab3/c++/";
    // Array files = getJsonFiles(dirPath);

    // if (argc <= 2)
    // {
    //     cout << "Недостаточно аргументов\n";
    //     return 1;
    // }

    // string query, file;
    // DoubleList args;
    // getArgs(query, file, args, argc, argv);

    // string Name;
    // bool isName = false;
    // getName(query, Name, isName);

    // DL<string> querys = split(query);

    // if (querys[0][0] == 'M') // Array
    // {
    //     processArray(Name, file, querys);
    // }
    // else if (querys[0][0] == 'L' && querys[0][1] == 'S') // SingleList
    // {
    //     processSingleList(Name, file, querys);
    // }
    // else if (querys[0][0] == 'L' && querys[0][1] == 'D') // DoubleList
    // {
    //     processDoubleList(Name, file, querys);
    // }
    // else if (querys[0][0] == 'Q') // Queue
    // {
    //    processQueue(Name, file, querys);
    // }
    // else if (querys[0][0] == 'S') // Stack
    // {
    //     processStack(Name, file, querys);
    // }
    // else if (querys[0][0] == 'T') // Tree
    // {
    //     Tree exm;
    //     DL<DL<int>> myTree;
    //     string fileName = file;
    //     json j;
    //     if (!(fileExists(fileName) && ValidFile(fileName)))
    //     {
    //         createNewFile(fileName, Name);

    //         readJson(fileName, j);

    //         if (j["Tree"][Name].is_null())
    //         {
    //             j["Tree"][Name] = json::array();
    //         }
    //     }
    //     else
    //     {
    //         readJson(fileName, j);

    //         if (j["Tree"][Name].is_null())
    //         {
    //             j["Stack"][Name] = json::array();
    //         }
    //         else
    //         {
    //             for (const auto &item : j["Tree"][Name])
    //             {
    //                 DL<int> newElem;
    //                 for (const int &elem : item)
    //                 {
    //                     newElem.LDPUSHT(elem);
    //                     exm.TINSERT(elem);
    //                 }
    //                 myTree.LDPUSHT(newElem);
    //             }
    //         }

    //         writeInJson(fileName, j);
    //     }
    //     switch (querys[0][2])
    //     {
    //     case 'N':
    //     {

    //         int newElem = atoi(querys[2].c_str());
    //         exm.TINSERT(newElem);
    //         myTree = exm.getLevels();
    //         break;
    //     }
    //     case 'S':
    //     {
    //         if (exm.TISCOMPLETE())
    //         {
    //             cout << "complete\n";
    //         }
    //         else
    //         {
    //             cout << "not complete\n";
    //         }
    //         break;
    //     }
    //     case 'E':
    //     {
    //         int newElem = atoi(querys[2].c_str());
    //         if (exm.TSEARCH(newElem))
    //         {
    //             cout << "presence\n";
    //         }
    //         else
    //         {
    //             cout << "not presence\n";
    //         }
    //         break;
    //     }
    //     default:
    //         break;
    //     }

    //     exm.PRINT();

    //     j["Tree"][Name].clear();
    //     for (int i = 0; i < myTree.len; i++)
    //     {
    //         DL<int> elem = myTree[i];
    //         json newElem = json::array();
    //         for (int j = 0; j < elem.len; j++)
    //         {
    //             newElem.push_back(elem[j]);
    //         }
    //         j["Tree"][Name].push_back(newElem);
    //     }
    //     writeInJson(fileName, j);
    // }
    // else if (querys[0][0] == 'H') // HT
    // {
    //     Hash_Table exm;

    //     string fileName = file;
    //     json j;
    //     DL<string> listKey;
    //     if (!(fileExists(fileName) && ValidFile(fileName)))
    //     {
    //         createNewFile(fileName, Name);

    //         readJson(fileName, j);

    //         if (j["HT"][Name].is_null())
    //         {
    //             j["HT"][Name] = json::array();
    //         }
    //     }
    //     else
    //     {
    //         readJson(fileName, j);

    //         if (j["HT"][Name].is_null())
    //         {
    //             j["HT"][Name] = json::array();
    //         }
    //         else
    //         {
    //             for (const auto &item : j["HT"][Name])
    //             {
    //                 for (const auto &[key, value] : item.items())
    //                 {
    //                     listKey.LDPUSHT(key);
    //                     exm.HSET(key, value);
    //                 }
    //             }
    //         }

    //         writeInJson(fileName, j);
    //     }
    //     switch (querys[0][1])
    //     {
    //     case 'S':
    //     {
    //         string key = querys[2];
    //         if (listKey.LDISINDEX(key) == -1)
    //         {
    //             listKey.LDPUSHT(key);
    //         }
    //         string value = querys[3];
    //         exm.HSET(key, value);
    //         break;
    //     }
    //     case 'G':
    //     {
    //         string key = querys[2];
    //         cout << exm.HGET(key) << "\n";
    //         break;
    //     }
    //     case 'D':
    //     {
    //         string key = querys[2];
    //         listKey.LDDELV(key);
    //         exm.HDEL(key);
    //         break;
    //     }
    //     default:
    //         break;
    //     }

    //     exm.PRINT();

    //     j["HT"][Name].clear();
    //     for (int i = 0; i < listKey.len; i++)
    //     {
    //         string key = listKey.LDGET(i);
    //         if (key == "There isn't such elem\n")
    //         {
    //             break;
    //         }
    //         string value = exm.HGET(key);
    //         json elem;
    //         elem[key] = value;
    //         j["HT"][Name].push_back(elem);
    //     }
    //     writeInJson(fileName, j);
    // }
    // else
    // {
    //     cout << "incorrect input\n";
    // }
    // interface(argc, argv);
    //  // interface(argc, argv);
    ::testing::InitGoogleTest(&globalArgc, globalArgv);
    int res = RUN_ALL_TESTS();

    return res;
}
