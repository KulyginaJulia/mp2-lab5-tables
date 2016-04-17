#include "polinom.h"
#include "monom.h"
#define eps 0.0001

//Реализация структуры Node
void Node :: SetMonom(Monom x) {
	this->m = x;
}
void Node :: SetNext(Node *n) {
	next = n;
}
Node* Node :: GetNext(){
	return next;
}
Monom Node :: GetMonom() {
	return m;
}

Node :: Node() {
	SetMonom(Monom());
	SetNext(NULL);
}

Node :: Node(Monom x) {
	this->SetMonom(x);
	this->SetNext(NULL);
}
Node :: Node(Monom x, Node* n) {
	SetMonom(x);
	SetNext(n);
}

//Node :: Node(Node &N) : m(N.m), next(N.next) {
//	//this->m = N.m;
//	//this->next = N.next;
//}

Node :: ~Node(){}
//Реализация Polinom

Polinom :: Polinom (Node *next){

	if (next == NULL)
		throw "List without head";
	this->head = next;
}
Polinom :: Polinom(){
	head = NULL;
}

Polinom :: Polinom(Polinom &m){
	Node *tmp = m.head->next;
	Node *tmp_this;
	if (!m.head)
	{
		this->head = NULL;
		return;
	}
	this->head = new Node(m.head->m);
	tmp_this = this->head; 
	while(tmp != NULL){
		this->InsertLast(tmp_this, tmp->m);
		tmp_this = tmp_this->next;
		tmp = tmp->next;
	}
	tmp_this->next = NULL;
}
Polinom :: ~ Polinom(){
	DeleteList();
}
void Polinom :: InsertLast(Node *curr, Monom &data){
	if (!curr)
		throw "insertion after null pointer";
	curr->next = new Node(data);
}
void Polinom :: InsertMiddle(Node *curr, Monom &data){
	Node *elem = new Node(data, curr->next);
	curr->next =  elem;
}
void Polinom :: InsertFirst(Monom &data){
	Node *elem = new Node(data, head);
	head = elem;
}
void Polinom :: DeleteFirst(){
	Node *tmp = head;
	head = head->next;
	delete tmp;
}
void Polinom :: DeleteList(){
	while(head != NULL)
		DeleteFirst();
}
void Polinom :: DeleteMiddle(Node *&prev){
	Node *tmp = prev;
	prev->next = tmp->next;
	delete tmp;
}
void Polinom :: Search(Monom &key){
	Node *tmp = head; 

	bool flag = false;
	while (tmp != NULL){
		if (tmp->m < key) 
			tmp = tmp->next;
		else 
		{
			flag = true;
			break;
		}
	}
	if (flag == true){
		if (tmp->m != key) 
			cout << "Wasn`t found";
	}
}
Polinom Polinom :: operator + (const Polinom& right) const
{
	Polinom res;
	Node* current_this = this->head;
	Node* current_right = right.head;
	Node* current_res;

	if (this->head == 0)
	{
		return res = right;
	}
	if (right.head == 0)
	{
		return res = *this;
	}

	res.InsertFirst(Monom());
	current_res = res.head;

	while ((current_this != NULL) && (current_right != NULL))
	{
		if (current_this->m < current_right->m)
		{
			res.InsertLast(current_res, current_this->m);
			current_this = current_this->next;
			current_res = current_res->next;
		} 
		else if (current_this->m > current_right->m)
		{
			res.InsertLast(current_res,current_right->m);
			current_right = current_right->next;
			current_res = current_res->next;
		}
		else 
		{
			if (current_this->m + current_right->m != 0){
				res.InsertLast(current_res, current_this->m + current_right->m);
				current_this = current_this->next;
				current_right = current_right->next;
				current_res = current_res->next;
			}
		}
	}
	while (current_this != NULL) {
		res.InsertLast(current_res, current_this->m);
		current_this = current_this->next;
		current_res = current_res->next;
	}
	while (current_right != NULL) {
		res.InsertLast(current_res, current_right->m);
		current_right = current_right->next;
		current_res = current_res->next;
	}
	res.DeleteFirst();
	return res;
}

ostream &operator<<(ostream &ostr,  const Polinom& p) // вывод
{
	Node* tmp = p.head;

	while (tmp != NULL){
		ostr << "(" << tmp->m << ") ";
		ostr << "  ";
		tmp = tmp->next;
	}
	ostr << endl;
	return ostr;
}
Polinom Polinom :: operator-(const Polinom& right) const
{
	Polinom res;

	if (right.head == NULL)
	{
		return res = *this;
	}
	if (this->head == NULL)
	{
		Monom m(-1,0,0,0);
		res = right * m;
		return res;
	}
	Monom m(-1,0,0,0);
	res = (*this) + right * m;
	return res;
}

Polinom Polinom :: operator*( const Monom& right) const
{
	Polinom res;
	Node *current_res;
	Node* current = this->head;
	res.InsertFirst(Monom());
	current_res = res.head;
	while (current != NULL)
	{
		res.InsertLast(current_res, current->m * right);
		current = current->next;
		current_res = current_res->next;
	}
	res.DeleteFirst();
	return res;
}
Polinom& Polinom :: operator=(const Polinom &A){
	if (this == &A) {
		return *this;
	}
	else {	
		this->DeleteList();

		Node *tmp;
		Node *tmp_this;
		if (!A.head)
		{
			this->head = NULL;
			return *this;
		}

		this->head = new Node(A.head->m);
		tmp = A.head->next;
		tmp_this = this->head; 
		while(tmp != NULL){
			this->InsertLast(tmp_this, tmp->m);
			tmp_this = tmp_this->next;
			tmp = tmp->next;
		}
		tmp_this->next = NULL;
	}	
	return *this;
}
Polinom Polinom :: operator*(const Polinom& right) const
{
	Polinom res;
	Polinom temp;
	Node* current = this->head;

	while (current != NULL) {
		cout<<current->m;

		temp = right * current->m;
		
		cout << "temp " << temp << "\n";
		cout << "res before plus " << res << "\n";
		
		res = temp + res;

		cout << "res after plus " << res << "\n";

		current = current->next;
	}

	return res;
}
Polinom Polinom ::  Entering(){
	bool flag1 = true;
	int i = 0;
	cout << "Enter polinom" << endl;
	while (flag1 == true){
		Monom a;
		cout << "Enter monom" << endl;
		a.CreateMonom();
		this->InsertFirst(a);
		cout << "Polinom was over? Enter Yes(1) or No(2)" << endl;
		int m;
		cin >> m;
		if (m != 2)
			flag1 = false;
	}
	return *this;
}

Polinom	Polinom :: DoOperation(Polinom B, char op){
	Polinom C;
	if (op == '+')
		C = *this + B;
	if (op == '-')
		C = *this - B;
	if (op == '*')
		C = *this * B;
	return C;
}
void Polinom:: Clear(){
	if ((head->m.coeff != 0) && (head->next != NULL))
		while (head != NULL){
			if (head->m.coeff == 0)
				DeleteFirst();
	}
}
void CheckOperation(char op){
		if ((op != '+') && (op != '-') && (op != '*'))
			throw "Operation is uncorrect";
}