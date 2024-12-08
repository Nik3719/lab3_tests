#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Tools.h"
#include "queue.h"

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(const int &value) : data(value), left(nullptr), right(nullptr) {};
};

class Tree
{
    TreeNode *root;
    void Allocation(TreeNode *node);
    TreeNode *downTree(TreeNode *node, int value);
    TreeNode *RightOrLeft(TreeNode *node, int &value);
    int countNodes(TreeNode *node);
    bool isComplete(TreeNode *node, int index, int numberNodes);
    int height(TreeNode *node);
    TreeNode *findNode(TreeNode *node, const int &value);
    void unsafePrint(TreeNode *root, int space = 0);

    void LoadLevel(TreeNode *node, int level, DL<int> &levelValues);

public:
    Tree();
    ~Tree();

    void TINSERT(int elem);
    bool TSEARCH(int elem);

    bool TISCOMPLETE();

    void PRINT() { unsafePrint(root); }
    DL<DL<int>> getLevels();
};