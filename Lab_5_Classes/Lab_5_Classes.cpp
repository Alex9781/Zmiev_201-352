#include <iostream>
#include "Matrix.h"

class P
{
public:
	int x;
	int y;

	P(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	P() { }
};

class C : public virtual P
{
public:
	int r;

	C(int x, int y, int r)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
	C() { }
};

class S : public virtual P
{
public:
	int a;
	S(int x, int y, int a)
	{
		this->x = x;
		this->y = y;
		this->a = a;
	}
	S() {}
};

class SC : public C, public S
{
public:
	SC(int x, int y, int r)
	{
		S::x = x;
		S::y = y;
		C::r = r;
	}
};

int main()
{
	Matrix m1(2, 2);
	m1.Input();
	Matrix m2 = -m1;
	m2.Print();

}