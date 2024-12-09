#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "DNode.h"
#include "Tools.h"

using namespace std;

class Queue
{
	DNode *front;
	DNode *rear;
	int len = 0;

public:
	Queue();
	bool isEmpty() { return front == nullptr; }
	~Queue();
	void QPUSH(string elem);
	string QPOP();
	string QGET(int index);
	void PRINT();
	int QLEN() { return this->len; }
};