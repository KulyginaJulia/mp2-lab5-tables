// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������

#pragma once

#include <iostream>
#include "monom.h"

using namespace std;

struct Node{
//����� Node
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

	void PrintPolinom(Polinom *head);//������ ��������
	
	void InsertLast(Node *curr, Monom &data);//������� ������ � ����� ������
	void InsertFirst(Monom &data); //������� ������ � ������ ������
	void InsertMiddle(Node *curr, Monom &data); //������� ������ � �������� ������
	
	void DeleteFirst();//�������� �������
	void DeleteList(); //�������� ������
	void DeleteMiddle(Node *&head);//�������� �� ��������
	
	void Search(Monom &key);//�����	
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
