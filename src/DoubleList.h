#pragma once
#include <string>
#include <iostream>
#include "Tools.h"
#include "DNode.h"

using namespace std;

class DoubleList
{
    DNode *head;
    DNode *tail;
    int len = 0;

public:
    DoubleList(int capacity = 0);
    ~DoubleList();
    void LDPUSHH(string elem);
    void LDPUSHT(string elem);
    string LDDELH();
    void LDDELT();
    void PRINT();
    string LDDELV(string elem);
    int LDISINDEX(string elem);
    string LDGET(int index);
    string &operator[](int index);
    int DLLEN() { return this->len; }
};
