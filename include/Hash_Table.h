#pragma once
#include <iostream>
#include <string>
#include "Tools.h"

using namespace std;

struct HashNode
{
	string key;
	string value;
	bool isOccupied;
	int NoneDeletePresence;
	HashNode() : value(""), key(""), isOccupied(false), NoneDeletePresence(1) {};
};

class Hash_Table
{
	HashNode *table;
	int size = 0;
	int hashFunc(string key);
	void resize(string key, string value);

public:
	Hash_Table(int = 0);
	~Hash_Table();
	void HSET(string key, string value);
	string HGET(string key);
	string HDEL(string key);
	void PRINT();
	friend void serialize(const Hash_Table &hashTable, const string &filename);
	friend void deserialize(Hash_Table &hashTable, const string &filename);
};
