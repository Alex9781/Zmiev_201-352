#include <iostream>
#include <deque>

using namespace std;

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

class Convex : public deque<Point>
{
private:

public:

	void add(Point p)
	{
		if (size() == 0)
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
			cout << p.getX() << " " << p.getY() << endl;
			this->pop_front();
			this->push_back(p);
		}
	}
};

int main()
{
	Convex c1 = Convex();

	c1.add(Point(10, 0));
	c1.add(Point(0, 10));
	c1.add(Point(10, 10));
	c1.add(Point(0, 0));

	c1.print();
}
