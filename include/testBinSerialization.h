#include "binSerilisation.h"
#include <gtest/gtest.h>

// Тест для сериализации и десериализации Array
TEST(SerializationTest, ArrayTest)
{
    Array array;
    array.MPUSH("one");
    array.MPUSH("two");
    array.MPUSH("three");

    serialize(array, "array_test.bin");

    Array newArray;
    deserialize(newArray, "array_test.bin");

    ASSERT_EQ(array.MLEN(), newArray.MLEN());
    for (int i = 0; i < array.MLEN(); ++i)
    {
        EXPECT_EQ(array.MGET(i), newArray.MGET(i));
    }
}

// Тест для SingleList
TEST(SerializationTest, SingleListTest)
{
    SingleList list;
    list.LSPUSHT("one");
    list.LSPUSHT("two");
    list.LSPUSHT("three");

    serialize(list, "singlelist_test.bin");

    SingleList newList;
    deserialize(newList, "singlelist_test.bin");

    ASSERT_EQ(list.LSLEN(), newList.LSLEN());
    for (int i = 0; i < list.LSLEN(); ++i)
    {
        EXPECT_EQ(list[i], newList[i]);
    }
}

// Тест для DoubleList
TEST(SerializationTest, DoubleListTest)
{
    DoubleList list;
    list.LDPUSHT("one");
    list.LDPUSHT("two");
    list.LDPUSHT("three");

    serialize(list, "doublelist_test.bin");

    DoubleList newList;
    deserialize(newList, "doublelist_test.bin");

    ASSERT_EQ(list.DLLEN(), newList.DLLEN());
    for (int i = 0; i < list.DLLEN(); ++i)
    {
        EXPECT_EQ(list[i], newList[i]);
    }
}

// Тест для Queue
TEST(SerializationTest, QueueTest)
{
    Queue queue;
    queue.QPUSH("one");
    queue.QPUSH("two");
    queue.QPUSH("three");

    serialize(queue, "queue_test.bin");

    Queue newQueue;
    deserialize(newQueue, "queue_test.bin");

    ASSERT_EQ(queue.QLEN(), newQueue.QLEN());
    for (int i = 0; i < queue.QLEN(); ++i)
    {
        EXPECT_EQ(queue.QGET(i), newQueue.QGET(i));
    }
}

// Тест для Stack
TEST(SerializationTest, StackTest)
{
    Stack stack;
    stack.SPUSH("one");
    stack.SPUSH("two");
    stack.SPUSH("three");

    serialize(stack, "stack_test.bin");

    Stack newStack;
    deserialize(newStack, "stack_test.bin");

    ASSERT_EQ(stack.SLEN(), newStack.SLEN());
    for (int i = 0; i < stack.SLEN(); ++i)
    {
        EXPECT_EQ(stack.SGET(i), newStack.SGET(i));
    }
}

// Тест для Hash_Table
TEST(SerializationTest, HashTableTest)
{
    Hash_Table hashTable(10);
    hashTable.HSET("key1", "value1");
    hashTable.HSET("key2", "value2");
    hashTable.HSET("key3", "value3");

    serialize(hashTable, "hashtable_test.bin");

    Hash_Table newHashTable(10);
    deserialize(newHashTable, "hashtable_test.bin");

    // ASSERT_EQ(hashTable.size, newHashTable.size);
    EXPECT_EQ(hashTable.HGET("key1"), newHashTable.HGET("key1"));
    EXPECT_EQ(hashTable.HGET("key2"), newHashTable.HGET("key2"));
    EXPECT_EQ(hashTable.HGET("key3"), newHashTable.HGET("key3"));
}

// Тест для Tree
TEST(SerializationTest, TreeTest)
{
    Tree tree;
    tree.TINSERT(10);
    tree.TINSERT(5);
    tree.TINSERT(15);
    tree.TINSERT(3);
    tree.TINSERT(7);

    tree.serialize("tree_test.bin");

    Tree newTree;
    newTree.deserialize("tree_test.bin");

    EXPECT_TRUE(newTree.TSEARCH(10));
    EXPECT_TRUE(newTree.TSEARCH(5));
    EXPECT_TRUE(newTree.TSEARCH(15));
    EXPECT_TRUE(newTree.TSEARCH(3));
    EXPECT_TRUE(newTree.TSEARCH(7));
    EXPECT_FALSE(newTree.TSEARCH(20));
}
