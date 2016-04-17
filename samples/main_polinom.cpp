#include "polinom.h"
#include <iostream>
void main()
{
	Polinom A, B;

	setlocale(LC_ALL, "Russian");
 	cout << "Enter a polinom A & B" << endl;

	A.Entering();
	B.Entering();
	cout << "The operations: +, -, * " << endl;



	cout << A << endl;

	char op;
	cin >> op;
	CheckOperation(op);

	Polinom C;
	C = A.DoOperation(B, op);
	C.Clear();
	cout << "result = " << C << endl;
}