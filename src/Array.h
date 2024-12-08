#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Tools.h"

using namespace std;

class Array
{
    int capacity = 0;
    int currentLen = 0;
    string *arr = nullptr;

public:
    Array() {}
    ~Array();
    Array(const Array &other);
    Array &operator=(const Array &other);

    void MPUSH(string elem);
    string MINSERT(string elem, int index);
    string MGET(int index);
    int MLEN();
    string MDEL(int index);
    void PRINT();
    string MSET(string elem, int index);
};
