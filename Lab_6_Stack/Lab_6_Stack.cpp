﻿#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

template <typename T>
class Stack
{
private:
	static const int DEFSIZE = 16;
	T* _arr;
	T* head;

public:
	Stack()
	{
		_arr = new T[DEFSIZE];
		head = _arr;
	}
	~Stack()
	{
		delete[] _arr;
	}

	void clear()
	{
		head = 0;
	}

	void push(T a)
	{
		*(head++) = a;
	}

	int pop()
	{
		return *(--head);
	}

	int top()
	{
		return *(head - 1);
	}
};

template <typename T>
class Queue
{
private:
	int _length;
	T* _array;
	int _size;
	int _head;
	int _tail;

	int forward(int index)
	{
		return ++index < _length ? index : 0;
	}

public:
	Queue(int lenght)
	{
		_array = new T[lenght];
		_length = lenght;

		Clear();
	}
	~Queue()
	{
		delete[] _array;
	}

	void Clear()
	{
		_head = 0;
		_size = 0;
		_tail = _length - 1;
	}

	bool Empty()
	{
		return _size == 0;
	}

	void Push(T a)
	{
		if (++_size < _length)
		{
			_array[forward(_tail)] = a;
		}
		else
		{

		}
	}

	T Pop();

	T Front()
	{
		return _array[_head];
	}
};

class Point {
private:
	double x, y;
public:
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	static bool equal(Point a, Point b)
	{
		return a.x == b.x && a.y == b.y;
	}

	static double area(Point a, Point b, Point c)
	{
		return 0.5 * ((a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x));
	}

	bool inside(Point a, Point b)
	{
		return (a.x <= x && x <= b.x || a.x >= x && x >= b.x) &&
			(a.y <= y && y <= b.y || a.y >= y && y >= b.y);
	}

	bool light(Point a, Point b)
	{
		double s = area(a, b, *this);
		return s < 0 || (s == 0.0 && !inside(a, b));
	}

	double getX()
	{
		return x;
	}

	double getY()
	{
		return y;
	}
};

class Convex : public std::deque<Point>
{
private:

public:

	void add(Point p)
	{
		if (this->size() == 0)
		{
			this->push_front(p);
			return;
		}
		if (size() == 1 && !Point::equal(front(), p))
		{
			push_back(p);
			return;
		}
		if (size() == 2)
		{
			if (Point::area(front(), back(), p) != 0.0)
			{
				push_front(p);
			}
			else
			{
				if (front().inside(back(), p))
				{
					pop_front();
					push_front(p);
				}
				else if (back().inside(p, front()))
				{
					pop_back();
					push_back(p);
				}
			}

			return;
		}
		if (size() >= 3)
		{
			int i;
			for (i = size(); !p.light(back(), front()) && i > 0; i--)
			{
				push_back(front());
				pop_front();
			}

			if (i > 0)
			{
				Point x = front();
				for (this->pop_front(); p.light(x, front()); )
				{
					x = front();
					pop_front();
				}
				push_front(x);

				x = back();
				for (this->pop_back(); p.light(back(), x); )
				{
					x = back();
					pop_back();
				}
				push_back(x);

				push_front(p);

			}
		}
	}

	int len()
	{
		return this->size();
	}

	void print()
	{
		for (int i = 0; i < this->size(); i++)
		{
			Point p = front();
			std::cout << p.getX() << " " << p.getY() << std::endl;
			this->pop_front();
			this->push_back(p);
		}
	}
};

struct Answer
{
	int id;
	string answ;
};

static bool operator<(const Answer a1, const Answer a2)
{
	return a1.id < a2.id;
}

int main()
{
	set<Answer> s1 = set<Answer>();

	Answer a1 = { 1, "sss" };
	Answer a2 = { 2, "ddd" };
	Answer a3 = { 3, "aaa" };
	Answer a4 = { 4, "fff" };
	Answer a5 = { 5, "qqq" };

	s1.insert(a1);
	s1.insert(a5);
	s1.insert(a3);
	s1.insert(a2);
	s1.insert(a4);
	s1.insert(a2);
	s1.insert(a3);

	for (auto i : s1)
	{
		cout << i.answ << endl;
	}

}