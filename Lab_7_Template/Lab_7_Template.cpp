#include <iostream>
#include <vector>

using namespace std;

struct MyStruct
{
	string Surname;
	string Name;
	int Age;
};

static bool operator>(MyStruct m1, MyStruct m2)
{
	if (m1.Surname == m2.Surname)
	{
		if (m1.Name == m2.Name)
		{
			return m1.Age > m2.Age;
		}
		else
		{
			return m1.Name > m2.Name;
		}
	}
	else
	{
		return m1.Surname > m2.Surname;
	}
}

template <typename T>
void Sort(vector<T>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size() - i - 1; j++)
		{
			if (arr[j] > arr[(uint64_t)j + (uint64_t)1])
			{
				T temp = arr[j];
				arr[j] = arr[(uint64_t)j + (uint64_t)1];
				arr[(uint64_t)j + (uint64_t)1] = temp;
			}
		}
	}
}

int main()
{
	vector<MyStruct> vect{ 
		{"aa", "qqqq", 10}, 
		{"ab", "qqww", 15}, 
		{"aa", "qqqq", 20}, 
		{"ab", "qqqq", 5}, 
		{"aa", "qqqq", 25} 
	};
	Sort(vect);

	for (auto i : vect)
	{
		cout << i.Surname << " " << i.Name << " " << i.Age << endl;
	}
}
