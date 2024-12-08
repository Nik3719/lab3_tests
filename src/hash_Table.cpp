#include"Hash_Table.h"

static string HTID = "0";
Hash_Table::Hash_Table(int size)
{
	this->size = size;
	this->table = new HashNode[size];
}


Hash_Table::~Hash_Table()
{
	delete[]table;
}

void Hash_Table::resize(string key, string value)
{
	int oldSize = size;
	if (size == 0)size++;
	size *= 2;
	HashNode* newTable = new HashNode[size];

	for (int j = 0; j < oldSize; j++)
	{
		if (table[j].isOccupied)
		{
			int index = hashFunc(table[j].key);
			while (newTable[index].isOccupied)
			{
				index = (index + 1) % size;
			}
			newTable[index].key = table[j].key;
			newTable[index].value = table[j].value;
			newTable[index].isOccupied = true;
			newTable[index].NoneDeletePresence = 3;
		}
	}
	delete []table;
	table = newTable;
	HSET(key, value);
}
void Hash_Table::HSET(string key, string value)
{
	if (size == 0)
	{
		resize(key, value);
	}
	int i = 0;
	int index = hashFunc(key);
	int oldIndex = index;
	while (table[index].isOccupied)
	{
		if (table[index].key == key)
		{
			table[index].value = value;
			return;
		}
		index = (index + 1) % size;
		if (oldIndex == index)
		{
			resize(key, value);
			return;
		}
	}
	table[index].key = key;
	table[index].value = value;
	table[index].isOccupied = true;
	table[index].NoneDeletePresence = 3;
}


int Hash_Table::hashFunc(string key)
{
	int k = ByteToInt(key);
	return (k % size);//+ i * (1 + (k % (size - 1)))) % size;
	// ������ ���-������� + i*������ ��� �������
}

string Hash_Table::HGET(string key)
{
	if (size == 0)
	{
		return "hash table if empty\n";
	}
	int i = 0;
	int index = hashFunc(key);
	int oldIndex = index;
	while (table[index].isOccupied)
	{
		if (table[index].NoneDeletePresence == 1)
		{
			return "There is not such key in this table\n";
		}
		if (table[index].key == key)
		{	
			return table[index].value;
		}
		
		index = (index + 1) % size;
		if (oldIndex == index)
		{
			break;
		}
	}
	return "There is not such key in this table\n";
}

string Hash_Table::HDEL(string key)
{
	if (size == 0)
	{
		return "hash table if empty\n";
	}
	int i = 0;
	int index = hashFunc(key);
	int oldIndex = index;
	while (table[index].isOccupied)
	{
		if (table[index].key == key)
		{
			string res = table[index].value;
			table[index].isOccupied = false;
			table[index].NoneDeletePresence = 2;
			return res;
		}
		index = (index + 1) % size;
		if (oldIndex == index)
		{
			return "There is not such key in this table\n";
		}
	}
	return "There is not such key in this table\n";
}

void Hash_Table::PRINT()
{
	int index = 0;
	while (index<size)
	{
		if (table[index].isOccupied)
		{
			cout << table[index].key << ":" << table[index].value << "\n";
		}
		index++;
	}

}

