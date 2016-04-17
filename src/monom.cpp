
#include "monom.h" 
#include "polinom.h"
Monom :: Monom (double coef, int a, int b, int c){

	if ((a < 0) || (b < 0) || (c < 0))
		throw "Degree has a negative value";

	this->deg = new int [3];
	
	this->deg[0] = a;
	this->deg[1] = b;
	this->deg[2] = c;
	this->coeff = coef;
}
Monom :: Monom(double coeff, int *deg){
	this->deg = new int[3];
	for (int i = 0; i < 3; i++)
		this->deg[i] = deg[i];
	this->coeff = coeff;
}
Monom :: ~Monom(){
	delete []this->deg;
}
Monom :: Monom(Monom &m){
	this->deg = new int [3];

	for (int i = 0; i < 3; i++)
		deg[i] = m.deg[i];
	this->coeff = m.coeff;
}
//Monom :: Monom(){
//	deg = NULL;
//	coeff = 0;
//}
ostream &operator<<(ostream &ostr, const Monom head) // вывод
{
	//while (head != NULL){
		ostr << "coeff = " << head.coeff << ", ";
		ostr << "deg = ";
		if (!head.deg) ostr << "NULL deg";
		for(int i = 0; i < 3; i++ )
		ostr  << head.deg[i];
		ostr << " ";
	//		}
	return ostr;
}
double Monom :: GetCoeff() const
 {
 	return coeff;
 }
 
 int* Monom :: GetDegree() const
 {
 	return deg;
 }
 
 void Monom :: SetCoeff(double c)
 {
 	coeff = c;
 }
 
 void Monom :: SetDegree(int *d)
 {
	 for(int i = 0; i < 3; i++)
 		deg[i] = d[i];
 }
 
 Monom& Monom :: operator=(const Monom& A)
 {
 	if (this == &A) {
 		return *this;
 	}
 	coeff = A.GetCoeff();
 	
	if (!deg)
		deg = new int[3];
	for (int i = 0; i < 3; i++)
		this->deg[i] = A.deg[i];
	
 	return *this;
 }
 
 bool operator==(const Monom& A,const Monom& B)
 {
	 bool flag = true;
	 for (int i = 0; i < 3; i++)
		 if (A.deg[i] != B.deg[i])
			 flag =  false;
 	return flag;
 }
 
 bool operator!=(const Monom& A, const Monom& B)
 {
 	return !(A == B);
 }
 
bool operator < (const Monom& A, const Monom& B)
{
	 int powerA = A.deg[0]*100 + A.deg[1]*10 + A.deg[2];
	 int powerB = B.deg[0]*100 + B.deg[1]*10 + B.deg[2];
	 if (powerA < powerB)
 		return true;
	 return false;
}
 
 bool operator > (const Monom& A,const Monom& B)
 {
	 int powerA = A.deg[0]*100 + A.deg[1]*10 + A.deg[2];
	 int powerB = B.deg[0]*100 + B.deg[1]*10 + B.deg[2];
	 if (powerA > powerB)
 		return true;
	 return false;
 }
Monom Monom :: operator + (const Monom &B)
 {
	int powerA = this->deg[0]*100 + this->deg[1]*10 + this->deg[2];
	int powerB = B.deg[0]*100 + B.deg[1]*10 + B.deg[2];
	if (powerA != powerB){
 		throw "Different degrees";
 	}
 	Monom res(this->GetCoeff() + B.GetCoeff(), this->GetDegree());
 	return res;
 }
 
Monom Monom :: operator - (const Monom& B) {
	int powerA = this->deg[0]*100 + this->deg[1]*10 + this->deg[2];
	int powerB = B.deg[0]*100 + B.deg[1]*10 + B.deg[2];
	if (powerA != powerB){
 		throw "Different degrees";
 	}
 	Monom res(this->GetCoeff() - B.GetCoeff(), this->GetDegree());
 	return res;
}

Monom Monom :: operator*(const Monom& B){
	double m = this->GetCoeff() * B.GetCoeff();
	Monom res(m, 0, 0, 0);
	for (int i = 0; i <3; i++ ){
		res.deg[i] = this->deg[i] + B.deg[i];
		if (res.deg[i] > 9)
			throw "degree is over 9";
	}
	return res;
}
Monom Monom :: CreateMonom(){	
		cin >> this->coeff;
		for (int i = 0; i < 3; i++){
			cin >> this->deg[i];
			if ((deg[i] > 9) || (deg[i] < 0))
				throw "degrees is uncorrect";
		}
		return *this;
}