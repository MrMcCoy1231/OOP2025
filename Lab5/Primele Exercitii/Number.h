#pragma once
class Number
{
	int baza;
	char* nr;

public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();

	Number(int x);

	Number(const Number& x); // Copy Construsctor
	Number(Number&& x) noexcept;// Move Constructor

	//Operatori de adunare si scadere
	friend Number operator+(const Number& a,const Number& b);
	friend Number operator-(const Number& a,const Number& b);
	
	//Operator de asignare
	
	void operator=(const Number& b);
	void operator=(int b);
	void operator=(const char* b);
	//Operatori de adunare/scadere si asignare
	
	friend Number operator+=(Number& a, const Number& b);
	friend Number operator-=(Number& a, const Number& b);

	//-- pt postfix si prefix

	Number& operator--(); //prefix
	Number operator--(int); //postfix

	//Operator care iti returneaza elementul de pe index
	char& operator[](int index);

	//Operatori relationali

	friend bool operator<(const Number& a, const Number& b);
	friend bool operator>(const Number& a, const Number& b);
	friend bool operator<=(const Number& a, const Number& b);
	friend bool operator>=(const Number& a, const Number& b);
	friend bool operator==(const Number& a, const Number& b);
	friend bool operator!=(const Number& a, const Number& b);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount();
	int  GetBase();
};
