// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once

#include <iostream>
using namespace std;

class Monom{
public:
	double coeff;
	int *deg;

	//Monom();
	Monom(double coeff, int *deg);
	Monom(double coef = 0, int a = 0, int b = 0, int c = 0);
	Monom(Monom &m);
	~Monom();

	friend ostream &operator<<(ostream &ostr, const Monom head);
	double GetCoeff() const;
	int * GetDegree() const;
	void SetCoeff(double c);
	void SetDegree(int *d);

	friend bool operator == (const Monom& A, const Monom& B);
 	friend bool operator != (const Monom& A, const Monom& B);
 	friend bool operator < (const Monom& A, const Monom& B);
 	friend bool operator > (const Monom& A, const Monom& B);
 	Monom& operator = (const Monom& B);

	Monom operator + (const Monom &B);
 	Monom operator - (const Monom &B);
	Monom operator * (const Monom &B);

	Monom CreateMonom();
};