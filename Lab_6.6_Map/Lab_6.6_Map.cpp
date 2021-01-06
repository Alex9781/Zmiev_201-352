#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> m1 = map<string, int>();
    
    string n;
    while (cin >> n) //ctrl+z
    {
        m1[n]++;
    }

    int sum = 0;
    for (auto i : m1)
    {
        sum += i.second;
    }

    for (auto i : m1)
    {
        cout << i.first << ": " << (float)i.second / sum * 100 << "%" << endl;
    }
}
