#include <iostream>
#include "Matrix.h"

int main()
{
	Matrix m1(2, 2);
	m1.Input();
	//m1.Print();
	//Matrix m2(1, 2);
	//m2.Input();
	//m2.Print();

	//Matrix m3 = Matrix::Sum(m1, m1);
	//m3.Print();

	//Matrix* m4 = Matrix::Mult(m1, m1);
	//m4->Print();

	Matrix* m4 = Matrix::Mult(m1, 10);
	m4->Print();

	//std::cout << m1.Trace() << std::endl;

	//std::cout << m1.Det() << std::endl;

	//Matrix m5 = Matrix::Mult(m1, 3);
	//m5.Print();


	/*int a = 10;
	int* p = &a;
	int& r = a;
	
	std::cout << r;*/

}