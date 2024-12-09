#pragma once
#include <string>
#include <iostream>
#include "DNode.h"
#include "Tools.h"

using namespace std;

class Stack
{
	DNode *spointer;
	int len = 0;

public:
	Stack();
	bool isEmpty() { return spointer == nullptr; }
	~Stack();
	void SPUSH(string elem);
	string SPOP();
	string SGET(int index);
	void PRINT();
	string &operator[](int index);
	int SLEN() { return this->len; }
};