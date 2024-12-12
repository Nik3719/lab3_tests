#include <gtest/gtest.h>
#include "Hash_Table.h"

class HashTableTest : public ::testing::Test {
protected:
    Hash_Table* hashTable;

    void SetUp() override {
        hashTable = new Hash_Table(5);
    }

    void TearDown() override {
        delete hashTable;
    }
};

// Test initialization
TEST_F(HashTableTest, InitializationTest) {
    EXPECT_NO_THROW(Hash_Table(5));
}

// Test insertion
TEST_F(HashTableTest, InsertTest) {
    hashTable->HSET("key1", "value1");
    EXPECT_EQ(hashTable->HGET("key1"), "value1");
}

// Test overwrite existing key
TEST_F(HashTableTest, OverwriteTest) {
    hashTable->HSET("key1", "value1");
    hashTable->HSET("key1", "new_value");
    EXPECT_EQ(hashTable->HGET("key1"), "new_value");
}

// Test non-existing key retrieval
TEST_F(HashTableTest, GetNonExistingKeyTest) {
    EXPECT_EQ(hashTable->HGET("unknown_key"), "There is not such key in this table\n");
}

// Test deletion of existing key
TEST_F(HashTableTest, DeleteExistingKeyTest) {
    hashTable->HSET("key1", "value1");
    EXPECT_EQ(hashTable->HDEL("key1"), "value1");
    EXPECT_EQ(hashTable->HGET("key1"), "There is not such key in this table\n");
}

// Test deletion of non-existing key
TEST_F(HashTableTest, DeleteNonExistingKeyTest) {
    EXPECT_EQ(hashTable->HDEL("unknown_key"), "There is not such key in this table\n");
}

// Test table resize during insertion
TEST_F(HashTableTest, ResizeTest) {
    hashTable->HSET("key1", "value1");
    hashTable->HSET("key2", "value2");
    hashTable->HSET("key3", "value3");
    hashTable->HSET("key4", "value4");
    hashTable->HSET("key5", "value5");
    hashTable->HSET("key6", "value6");  // Triggers resize

    EXPECT_EQ(hashTable->HGET("key6"), "value6");
}

// Test table print (manual validation)
TEST_F(HashTableTest, PrintTest) {
    hashTable->HSET("key1", "value1");
    hashTable->HSET("key2", "value2");
    EXPECT_NO_THROW(hashTable->PRINT());
}

// Test hash function boundary conditions
TEST_F(HashTableTest, HashFunctionBoundaryTest) {
    hashTable->HSET("a", "valueA");
    hashTable->HSET("b", "valueB");
    EXPECT_EQ(hashTable->HGET("a"), "valueA");
    EXPECT_EQ(hashTable->HGET("b"), "valueB");
}

// Test inserting into full table
TEST_F(HashTableTest, FullTableInsertTest) {
    for (int i = 0; i < 100; ++i) {
        hashTable->HSET("key" + std::to_string(i), "value" + std::to_string(i));
    }
    EXPECT_EQ(hashTable->HGET("key99"), "value99");
}

// Test deleting after resize
TEST_F(HashTableTest, DeleteAfterResizeTest) {
    hashTable->HSET("key1", "value1");
    hashTable->HSET("key2", "value2");
    hashTable->HSET("key3", "value3");
    hashTable->HSET("key4", "value4");
    hashTable->HSET("key5", "value5");
    hashTable->HSET("key6", "value6");  // Triggers resize

    EXPECT_EQ(hashTable->HDEL("key3"), "value3");
    EXPECT_EQ(hashTable->HGET("key3"), "There is not such key in this table\n");
}

