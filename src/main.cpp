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
#include "binSerilisation.h"

#include <gtest/gtest.h>
#include "testArray.h"
#include "testStack.h"
#include "testQueue.h"
#include "testTree.h"
#include "testSingleList.h"
#include "testDoubleList.h"
#include "testHash_Table.h"
#include "testInterface.h"
#include "testBinSerialization.h"
#include"testDL.h"

int globalArgc;
char **globalArgv;

char *arg[] = {"--file", "11.json", "--query", "SPUSH 1 3"};

int main(int argc, char *argv[])
{
    // Hash_Table ht(5);
    // // ht.HSET("1", "val1");
    // // ht.HSET("2", "val2");

    // // ht.HSET("3", "val3");

    // // serialize(ht, "1.bin");
    // deserialize(ht, "1.bin");
    // ht.PRINT();
    // return 0;
    
    globalArgc = argc;
    globalArgv = argv;

    ::testing::InitGoogleTest(&globalArgc, globalArgv);

    return RUN_ALL_TESTS();
}
