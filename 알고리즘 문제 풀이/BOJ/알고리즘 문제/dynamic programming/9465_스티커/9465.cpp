//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

int cache[2][100001];
int point[2][100001];
int n;

//f(0,x)=max(f(1,x-2),f(1,x-1))+point[0][x]

bool isRange(int x)
{
	if (x < 0 || x >= n)
		return false;
	return true;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int maxPoint(bool y, int x)
{
	if (!isRange(x))
		return 0;

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	return ret = max(maxPoint(!y, x - 2), maxPoint(!y, x - 1)) + point[y][x];
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < n; ++k)
				cin >> point[j][k];
		}
		memset(cache, -1, sizeof(cache));
		cout << max(maxPoint(0, n - 1), maxPoint(1, n - 1)) << endl;
	}
	
	return 0;
}