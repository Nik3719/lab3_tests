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
#include"testTree.h"
#include"testSingleList.h"
#include"testDoubleList.h"




int globalArgc;
char **globalArgv;

// TEST(Interface, FewArg)
// {
//     int buf = 2;
//     int exitCode = interface(buf, globalArgv);
//     EXPECT_EQ(exitCode, 1);

// }



int main(int argc, char **argv)
{
    globalArgc = argc;
    globalArgv = argv;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
