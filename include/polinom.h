// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов

#pragma once

#include <iostream>
#include "monom.h"

using namespace std;

struct Node{
//Звено Node
	Monom m;
	Node *next;

	Node();
	Node(Monom x, Node *next);
//	Node(Node &N);
	Node (Monom x);
	~Node();
	void SetMonom(Monom x);
	void SetNext(Node *n);
	Node * GetNext();
	Monom GetMonom();
	friend ostream &operator<<(ostream &ostr, const Node *head);
};

class Polinom
{
public:
	Node* head;

	Polinom();
	Polinom(Polinom &p);
	Polinom(Node *next);
	~Polinom();

	void PrintPolinom(Polinom *head);//Печать полинома
	
	void InsertLast(Node *curr, Monom &data);//вставка монома в конец списка
	void InsertFirst(Monom &data); //вставка монома в начало списка
	void InsertMiddle(Node *curr, Monom &data); //вставка монома в середину списка
	
	void DeleteFirst();//Удаление первого
	void DeleteList(); //Удаление списка
	void DeleteMiddle(Node *&head);//Удаление из середины
	
	void Search(Monom &key);//поиск	
	Polinom operator+ (const Polinom& right) const;
	Polinom operator-(const Polinom& right) const;
	Polinom operator*(const Monom& right) const;
	Polinom operator*(const Polinom& right) const;
	friend ostream &operator<<(ostream &ostr, const Polinom& p) ;
	Polinom& operator=(const Polinom &B);
	Polinom Entering();
	Polinom DoOperation(Polinom B, char op);
	void Clear();
};
	void CheckOperation(char op);
