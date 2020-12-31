#include <iostream>
#include <stack>

using namespace std;

bool Check(string std);

int main()
{
	cout << Check("{((2+4+6))*(568)()}") << endl;
	cout << Check("{((2+4+6))*[(568)]()}(") << endl;
}

bool Check(string str)
{
	stack<char> s1 = stack<char>();
	bool balanced = true;
	int i = 0;
	while (i < str.length() && balanced)
	{
		char symb = str[i];
		if (symb == '(' || symb == '{' || symb == '[')
		{
			s1.push(symb);
		}
		else if ((symb == ')' && s1.top() == '(') || (symb == '}' && s1.top() == '{') || (symb == ']' && s1.top() == '['))
		{
			if (s1.size() == 0)
			{
				balanced = false;
			}
			else
			{
				s1.pop();
			}
		}

		i++;
	}

	if (balanced && s1.size() == 0) return true;
	else return false;
}