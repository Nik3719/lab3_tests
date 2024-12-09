#pragma once
#include <gtest/gtest.h>
#include "Tree.h"

TEST(TreeTest, InsertionAndSearch)
{
    Tree tree;

    // Вставка элементов
    tree.TINSERT(10);
    tree.TINSERT(5);
    tree.TINSERT(20);
    tree.TINSERT(15);
    tree.TINSERT(25);

    // Проверка поиска элементов
    EXPECT_TRUE(tree.TSEARCH(10));
    EXPECT_TRUE(tree.TSEARCH(5));
    EXPECT_TRUE(tree.TSEARCH(20));
    EXPECT_TRUE(tree.TSEARCH(15));
    EXPECT_TRUE(tree.TSEARCH(25));
    EXPECT_FALSE(tree.TSEARCH(30));
}

TEST(TreeTest, CompleteCheck)
{
    Tree tree;

    // Полное дерево
    tree.TINSERT(10);
    tree.TINSERT(5);
    tree.TINSERT(15);
    tree.TINSERT(3);
    tree.TINSERT(7);
    tree.TINSERT(12);
    tree.TINSERT(18);

    EXPECT_TRUE(tree.TISCOMPLETE());

    // Неполное дерево
    tree.TINSERT(100);
    EXPECT_FALSE(tree.TISCOMPLETE());
}

TEST(TreeTest, HeightCalculation)
{
    Tree tree;

    EXPECT_EQ(tree.Height(), 0); // Пустое дерево

    // Дерево с одним элементом
    tree.TINSERT(10);
    EXPECT_EQ(tree.Height(), 1);

    // Дерево с несколькими уровнями
    tree.TINSERT(5);
    tree.TINSERT(20);
    tree.TINSERT(15);
    tree.TINSERT(25);
    EXPECT_EQ(tree.Height(), 3);
}

TEST(TreeTest, GetLevelsCheck)
{
    Tree tree;

    tree.TINSERT(10);
    tree.TINSERT(5);
    tree.TINSERT(15);
    tree.TINSERT(3);
    tree.TINSERT(7);
    tree.TINSERT(12);
    tree.TINSERT(18);

    DL<DL<int>> levels = tree.getLevels();

    EXPECT_EQ(levels.LDGET(0).LDGET(0), 10); // Корень
    EXPECT_EQ(levels.LDGET(1).LDGET(0), 5);  // Уровень 2, узел 1
    EXPECT_EQ(levels.LDGET(1).LDGET(1), 15); // Уровень 2, узел 2
    EXPECT_EQ(levels.LDGET(2).LDGET(0), 3);  // Уровень 3, узел 1
    EXPECT_EQ(levels.LDGET(2).LDGET(1), 7);  // Уровень 3, узел 2
    EXPECT_EQ(levels.LDGET(2).LDGET(2), 12); // Уровень 3, узел 3
    EXPECT_EQ(levels.LDGET(2).LDGET(3), 18); // Уровень 3, узел 4
}

TEST(TreeTest, PrintCheck)
{
    Tree tree;

    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());

    tree.TINSERT(10);
    tree.TINSERT(5);
    tree.TINSERT(15);
    tree.PRINT();

    std::cout.rdbuf(old); // Восстановить стандартный вывод

    std::string expected =
        "    15\n"
        "10\n"
        "    5\n";

    EXPECT_EQ(buffer.str(), expected);
}
