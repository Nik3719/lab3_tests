#pragma once
#include <gtest/gtest.h>
#include<sstream>
#include "Array.h"


TEST(Arr, method)
{
    // costructor
    Array myArr;
    // PUSH
    myArr.MPUSH("test");
    // GET
    EXPECT_EQ(myArr.MGET(0), "test");
    // operator =
    Array NewArr;
    NewArr = myArr;
    EXPECT_EQ(NewArr.MGET(0), "test");
    EXPECT_EQ(NewArr.MLEN(), myArr.MLEN());
    // GET
    EXPECT_EQ(NewArr.MGET(12132), "Такого индекса нет!\n");
    // Rsize
    NewArr.MPUSH("resizeArray");
    NewArr.MPUSH("resizeArray");
    NewArr.MPUSH("resizeArray");
    EXPECT_EQ(NewArr.MLEN(), 4);
    // PUSH
    EXPECT_EQ(NewArr.MGET(3), NewArr.MGET(2));
    // INSERT
    Array testInsert;
    // INSERT index 0
    testInsert.MINSERT("insert", 0);
    EXPECT_EQ(testInsert.MGET(0), "insert");
    // INSERT index 0 when there is elem
    testInsert.MINSERT("insert", 0);
    EXPECT_EQ(testInsert.MGET(0), testInsert.MGET(1));
    EXPECT_EQ(testInsert.MLEN(), 2);
    // INSERT in end
    NewArr.MINSERT("insert", NewArr.MLEN());
    EXPECT_EQ(NewArr.MGET(NewArr.MLEN() - 1), "insert");
    // INSERT in not exist index
    EXPECT_EQ(NewArr.MINSERT("notExistIndex", 231), "Такого индекса нет!");
    EXPECT_EQ(NewArr.MINSERT("notExistIndex", -1), "Такого индекса нет!");
    // вставили в центр но он расщирился
    NewArr.MINSERT("вставили в центр но он расщирился", 1);
    NewArr.MINSERT("вставили в центр но он расщирился", 1);
    NewArr.MINSERT("вставили в центр но он расщирился", 1);
    NewArr.MINSERT("вставили в центр но он расщирился", 1);
    NewArr.MINSERT("вставили в центр но он расщирился", 1);
    EXPECT_EQ(NewArr.MGET(1), "вставили в центр но он расщирился");
    // SET
    NewArr.MSET("setIn0", 0);
    NewArr.MSET("setIn-1", NewArr.MLEN() - 1);
    EXPECT_EQ(NewArr.MGET(0), "setIn0");
    EXPECT_EQ(NewArr.MGET(NewArr.MLEN() - 1), "setIn-1");
    // SET in not exist index
    EXPECT_EQ(NewArr.MSET("setIn-1", -1), "Такого индекса нет!");
    EXPECT_EQ(NewArr.MSET("setIn99999", 99999), "Такого индекса нет!");
    // DEL
    int lenNewArr = NewArr.MLEN();
    NewArr.MDEL(0);
    EXPECT_EQ(NewArr.MLEN() + 1, lenNewArr);
    // del not exist index
    NewArr.MDEL(-1231);
    EXPECT_EQ(NewArr.MLEN() + 1, lenNewArr);
    string NewArrElem = NewArr.MGET(3);
    string DelElem = NewArr.MDEL(3);
    EXPECT_TRUE(NewArrElem == DelElem);
    // costructor copy
    Array cp = NewArr;
    EXPECT_EQ(cp.MGET(0), NewArr.MGET(0));
    // PRINT
    Array arr1;
    arr1.MPUSH("1");
    stringstream buffer;
    streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    arr1.PRINT();
    cout.rdbuf(old);
    string output = buffer.str();
    EXPECT_EQ(output, "1 \n");
}