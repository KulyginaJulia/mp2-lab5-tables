#include  "table.h"
HashTable::HashTable()
{
	max_size = 10;
	data = new list<NodeTable>*[max_size];
	for (int i = 0; i < max_size; i++)
	{
		data[i] = new list < NodeTable > ;
	}
}

void HashTable::Insert(string key, Polinom* p)
{
	int hash = hashfunc(key);
	data[hash]->push_back(NodeTable(key, p));
}

void HashTable::Delete(string key)
{
	int hash = hashfunc(key);
	data[hash]->remove(NodeTable(key, NULL));
}

Polinom* HashTable::GetNode(string key)
{
	int hash = hashfunc(key);
	list<NodeTable>::const_iterator iterator;
	for (iterator = data[hash]->begin(); iterator != data[hash]->end(); ++iterator) {
		if (key == iterator->GetKey())
		{
			return iterator->GetElement();
		}
	}
	return NULL;
}

int HashTable::hashfunc(string s)
{
	int hash = 0;
	for (int i = 0; i < s.size(); i++)
	{
		hash += s[i];
	}
	return hash%max_size;
}