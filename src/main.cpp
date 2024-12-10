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
#include"binSerilisation.h"

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
    Queue arr;
    arr.QPUSH("1");
    arr.QPUSH("2");
    arr.QPUSH("3");
    serialize(arr, "1.bin");
    // deserialize(arr, "1.bin");
    // arr.PRINT();
    return 0;
    // globalArgc = argc;
    // globalArgv = argv;
    
    // ::testing::InitGoogleTest(&globalArgc, globalArgv);
    // int res = RUN_ALL_TESTS();

    // return res;
}
