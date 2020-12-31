#include <iostream>
#include <queue>

using namespace std;

bool Check(int num);

int main()
{
	queue<int> q1 = queue<int>();
	int n;
	cin >> n;
	int len = INT_MAX;
	int i = 1;

	while (q1.size() < n)
	{
		i++;
		if (Check(i))
		{
			q1.push(i);
		}
	}

	while (!q1.empty())
	{
		cout << q1.front() << endl;
		q1.pop();
	}
}

bool Check(int num)
{
	if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}