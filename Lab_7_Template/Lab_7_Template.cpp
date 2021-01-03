#include <iostream>
#include <vector>

using namespace std;

enum class MyEnum
{
	Surname,
	Name,
	Age
};
MyEnum sortField;

struct MyStruct
{
	string Surname;
	string Name;
	int Age;
};

static bool operator>(MyStruct m1, MyStruct m2)
{
	if (sortField == MyEnum::Surname)
	{
		return m1.Surname > m2.Surname;
	}
	else if (sortField == MyEnum::Name)
	{
		return m1.Name > m2.Name;
	}
	else if (sortField == MyEnum::Age)
	{
		return m1.Age > m2.Age;
	}

	return false;
}

static bool operator<(MyStruct m1, MyStruct m2)
{
	if (sortField == MyEnum::Surname)
	{
		return m1.Surname < m2.Surname;
	}
	else if (sortField == MyEnum::Name)
	{
		return m1.Name < m2.Name;
	}
	else if (sortField == MyEnum::Age)
	{
		return m1.Age < m2.Age;
	}

	return false;
}

template <typename T>
void Sort(T* arr, int first, int last)
{
	T mid, count;
	int f = first, l = last;
	mid = arr[(f + l) / 2];

	do
	{
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l)
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}

	} while (f < l);

	if (first < l) Sort(arr, first, l);
	if (f < last) Sort(arr, f, last);

}

int main()
{
	const int size = 6;
	MyStruct vect[size] = {
		{"a", "z", 10},
		{"b", "y", 15},
		{"c", "x", 20},
		{"d", "w", 50},
		{"e", "v", 25},
		{"f", "u", 30}
	};

	sortField = MyEnum::Surname;
	Sort(vect, 0, size - 1);

	for (auto i : vect)
	{
		cout << i.Surname << " " << i.Name << " " << i.Age << endl;
	}
	cout << endl;

	sortField = MyEnum::Name;
	Sort(vect, 0, size - 1);

	for (auto i : vect)
	{
		cout << i.Surname << " " << i.Name << " " << i.Age << endl;
	}
	cout << endl;

	sortField = MyEnum::Age;
	Sort(vect, 0, size - 1);

	for (auto i : vect)
	{
		cout << i.Surname << " " << i.Name << " " << i.Age << endl;
	}
	cout << endl;

	int i[size] = { 2, 5, 1, 3, 15, 2 };
	Sort(i, 0, size - 1);

	for (auto i : i)
	{
		cout << i << endl;
	}
	cout << endl;

	float f[size] = { 2.69, 2.54, 2.0001, 2.894, 2.111, 2.321 };
	Sort(f, 0, size - 1);

	for (auto i : f)
	{
		cout << i << endl;
	}
	cout << endl;
}
