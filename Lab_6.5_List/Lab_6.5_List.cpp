﻿#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<string>* groups = new list<string>[10];

	int index;
	int lastIndex = 0;
	string n;
	bool flag = true;

	while (cin >> index >> n)
	{
		if (index > lastIndex) lastIndex = index;
		groups[index].push_back(n);
	}

	for (int i = 1; i <= lastIndex; i++)
	{
		for (auto j : groups[i])
		{
			cout << i << " " << j << endl;
		}
		cout << endl;
	}
}