#pragma once

#include "polinom.h"
#include <string>
#include <list>
#include <vector>
using namespace std;

class NodeTable
{
private:
	string name;
	Polinom* element;
public:
	NodeTable();
	NodeTable(const NodeTable & r);
	NodeTable(string name_, Polinom* elem);

	string GetKey() const;
	Polinom* GetElement() const;
	NodeTable& operator=(const NodeTable &r);
	bool operator==(const NodeTable &r);
};

class Table
{
protected:
	virtual int Find(string key) = 0;
public:	
	virtual void Insert(string key, Polinom *p) = 0;
	virtual void Delete(string key) = 0;
	virtual Polinom* GetNode(string key) = 0 ;
};

class SortedTable: public Table
{
private:
	int count_data;
	int max_size;
	NodeTable* data;

	bool IsFull();
	void AddOrderly(string key, Polinom *p);
	void MoreMem();
	int Find(string key);
public:
	SortedTable();
	int GetCountData();
	void Insert(string key, Polinom *p);
	void Delete(string key);
	Polinom* GetNode(string key);
};

class HashTable : public Table
{
private:
	list<NodeTable> **data;
	int max_size;

	int hashfunc(string s);
	int Find(string key) { return 0; };
public:
	HashTable();

	void Insert(string key, Polinom *p);
	void Delete(string key);
	Polinom* GetNode(string key);
};