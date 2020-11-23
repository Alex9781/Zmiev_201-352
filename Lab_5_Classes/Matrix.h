#pragma once
#include <iostream>

//template <typename T>
class Matrix
{
private:
	int** matr;
	int rows;
	int cols;

	int findDet(int** a, int n)
	{ //����������� ������� ���������� ������������ �������
		if (n == 1)
			return a[0][0];
		else if (n == 2)
			return a[0][0] * a[1][1] - a[0][1] * a[1][0];
		else
		{
			int d = 0;
			for (int k = 0; k < n; k++) {
				int** m = new int* [n - 1];
				for (int i = 0; i < n - 1; i++)
				{
					m[i] = new int[n - 1];
				}
				for (int i = 1; i < n; i++)
				{
					int t = 0;
					for (int j = 0; j < n; j++)
					{
						if (j == k)
							continue;
						m[i - 1][t] = a[i][j];
						t++;
					}
				}
				d += pow(-1, k + 2) * a[0][k] * findDet(m, n - 1);
			}
			return d;
		}
	}

public:
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;

		matr = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matr[i] = new int[cols];
		}
	}

	~Matrix()
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete[] this->matr[i];
		}
		delete[] this->matr;
	}

	void Input()
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				std::cin >> this->matr[i][j];
			}
		}
	}

	void Print()
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				std::cout << matr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	static Matrix* Sum(Matrix& m1, Matrix& m2)
	{
		if (m1.rows == m2.rows && m1.cols == m2.cols)
		{
			Matrix* res = new Matrix(m1.rows, m1.cols);

			for (int i = 0; i < res->rows; i++)
			{
				for (int j = 0; j < res->cols; j++)
				{
					res->matr[i][j] = m1.matr[i][j] + m2.matr[i][j];
				}
			}

			return res;
		}
	}

	static Matrix* Mult(Matrix& m1, Matrix& m2)
	{
		if (m1.cols == m2.rows)
		{
			Matrix* res = new Matrix(m1.rows, m2.cols);
			for (int i = 0; i < res->rows; i++)
			{
				for (int j = 0; j < res->cols; j++)
				{
					res->matr[i][j] = 0;
					for (int k = 0; k < m1.cols; k++)
					{
						res->matr[i][j] += m1.matr[i][k] * m2.matr[k][j];
					}
				}
			}

			return res;
		}
	}

	static Matrix* Mult(const Matrix& m, double x)
	{
		Matrix* res = new Matrix(m.rows, m.cols);
		for (int i = 0; i < res->rows; i++)
		{
			for (int j = 0; j < res->cols; j++)
			{
				res->matr[i][j] = m.matr[i][j] * x;
			}
		}

		return res;
	}

	double Trace()
	{
		if (this->rows == this->cols)
		{
			double res = 0;
			for (int i = 0; i < this->rows; i++)
			{
				res += this->matr[i][i];
			}

			return res;
		}
	}

	double Det()
	{
		if (this->rows == this->cols)
		{
			return this->findDet(this->matr, this->cols);
		}
	}

	int GetRows()
	{
		return this->rows;
	}

	int GetCols()
	{
		return this->cols;
	}

	double GetElement(int i, int j)
	{
		return this->matr[i][j];
	}
};

