#include <iostream>
#include<string.h>
#include<vector>
using namespace std;

bool c[101];
int n;
int number[101];

void print()
{
	for (int i = 1; i <= n; ++i)
	{
		if (c[i])
			cout << i << endl;
	}
}

void checkSubSet(int start)
{
	vector<int> v;
	v.push_back(start);
	c[start] = true;
	int x = start;
	bool hasSet = false;
	while (1)
	{
		if (number[x] == start)
			hasSet = true;
		if (c[number[x]])
			break;

		x = number[x];
		v.push_back(x);
		c[x] = true;
	}
	if (!hasSet)
	{
		int size = v.size();
		for (int i = 0; i < size; ++i)
			c[v[i]] = false;
	}
}

int countSet()
{
	for (int i = 1; i <= n; ++i)
	{
		if (!c[i])
			checkSubSet(i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (c[i])
			++cnt;
	}
	return cnt;
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> number[i];
	memset(c, 0, sizeof(c));
	cout << countSet()<<endl;
	print();
	return 0;
}