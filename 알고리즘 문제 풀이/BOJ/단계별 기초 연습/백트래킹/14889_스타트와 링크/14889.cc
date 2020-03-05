#include<iostream>
#include<string.h>
using namespace std;

int N;
int Stat[21][21] = { 0 };
int Min = 40000;

int abs_sub(int a, int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

int search(int num, bool c[21],int sum1,int sum2)
{
	if (num == N)
		return 0;

	for (int i = num; i < N; ++i)
	{
		c[i] = true;
		int ret1 = sum1, ret2 = sum2;
		for (int j = 0; j < N; ++j)
		{
			int temp = Stat[i][j] + Stat[j][i];
			if (c[j] == 1)	ret1 += temp;
			else	ret2 -= temp;
		}
		int checkMin = abs_sub(ret1, ret2);
		if (Min > checkMin)
			Min = checkMin;
		search(i + 1, c, ret1, ret2);
		c[i] = false;
	}
	
	return Min;
}

int main()
{
	cin >> N;
	int total = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Stat[i][j];
			total += Stat[i][j];
		}
	}
	bool c[21];
	memset(c, 0, sizeof(c));
	cout << search(0, c, 0, total);

	return 0;
}