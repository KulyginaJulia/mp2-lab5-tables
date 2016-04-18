#include "table.h"

//SortedTable
int SortedTable::GetCountData() {
	return count_data;
}
bool SortedTable::IsFull() {
	if (count_data == max_size) {
		return true;
	}
	return false;
}

SortedTable::SortedTable()
{
	count_data = 0;
	max_size = 2;
	data = new NodeTable[max_size];
}

void SortedTable::MoreMem()
{
	NodeTable* temp = new NodeTable[max_size*2];
	for (int i = 0; i < max_size; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	max_size = 2 * max_size;
	data = temp;
}

int SortedTable::Find(string key)
{
	if (count_data==0)
	{
		return -1;
	}
	int l = -1;                    
	int r = count_data;
	int m;
	while (l < r - 1) {            
		m = (l + r) / 2;          
		if (data[m].GetKey() < key)
			l = m;
		else
			r = m;
	}
	return r;
}

void SortedTable::AddOrderly(string key, Polinom *p)
{
	if (count_data == 0)
	{
		data[0] = NodeTable(key, p);
		count_data++;
		return;
	}
	if (key<data[0].GetKey())
	{
		for (int i = count_data; i > 0; i--) {
			data[i] = data[i - 1];
		}
		data[0] = NodeTable(key, p);
		count_data++;
		return;
	}
	if (key>data[count_data-1].GetKey()) {
		data[count_data] = NodeTable(key, p);
		count_data++;
		return;
	}

	int index = Find(key);
	for (int i = count_data; i > index; i--) {
		data[i] = data[i - 1];
	}
	data[index] = NodeTable(key, p);
	count_data++;
	return;
}

void SortedTable::Insert(string key, Polinom* p)
{

	if (count_data==max_size)
	{
		MoreMem();
	}
	AddOrderly(key, p);
}

void SortedTable::Delete(string key)
{
	int index = Find(key);
	for (int i = index; i < count_data-1; i++)
	{
		data[i] = data[i + 1];
	}
	data[count_data - 1] = NodeTable("",NULL);
	count_data--;
}

Polinom* SortedTable::GetNode(string key)
{
	int index = Find(key);
	if (index == -1)
	{
		return NULL;
	}
	return data[index].GetElement();
}