#pragma once
#include<string>

using namespace std;

struct DNode
{
    string data;
    DNode* next;
    DNode* prev;
    DNode(string value) : data(value), next(nullptr), prev(nullptr) {};
};