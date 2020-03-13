#include<iostream>
using namespace std;
int cache[1001][1001] = { 0 };
int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int size1 = s1.size(), size2 = s2.size();
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			if (s1[i] == s2[j])
				cache[i + 1][j + 1] = cache[i][j] + 1;
			else
				cache[i + 1][j + 1] = max(cache[i + 1][j], cache[i][j + 1]);
		}
	}
	cout << cache[size1][size2];

	return 0;
}