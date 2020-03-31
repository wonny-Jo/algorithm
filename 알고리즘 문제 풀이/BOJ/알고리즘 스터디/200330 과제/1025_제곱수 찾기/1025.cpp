#include<iostream>
#include<math.h>
using namespace std;
int N, M;
string s[10];

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

bool isSquare(int n)
{
	int sqrt_n = pow(n, 0.5);
	if (n == pow(sqrt_n, 2))
		return true;
	return false;
}

int searchSquare(int startR, int startC, int jumpR, int jumpC)
{
	if (jumpR == 0 && jumpC == 0)
	{
		if(isSquare(s[startR][startC] - '0'))
			return s[startR][startC] - '0';
		return -1;
	}

	int max = -1;
	int i = startR, j = startC;
	int num = 0;
	
	while (isRange(i, j))
	{
		num *= 10;
		num += s[i][j] - '0';
		if (isSquare(num) && max < num)
			max = num;
		i += jumpR;
		j += jumpC;
	}
	return max;
}

int searchMax(int startR, int startC)
{
	int max = -1;
	for (int i = -(N-1); i < N; ++i)
	{
		for (int j = -(M-1); j < M; ++j)
		{
			int temp = searchSquare(startR, startC, i, j);
			if (max < temp)
				max = temp;
		}
	}
	return max;
}


int search()
{
	int max = -1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M;++j)
		{
			int temp=searchMax(i, j);
			if (max < temp)
				max = temp;
		}
	}
	return max;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> s[i];
	
	cout << search();
	return 0;
}