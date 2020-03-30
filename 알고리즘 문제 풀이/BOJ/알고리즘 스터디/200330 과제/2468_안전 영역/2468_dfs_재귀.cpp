#include<iostream>
#include<string.h>
using namespace std;
int N;
bool zero[101][101] = { 0 };
int arr[101][101];
bool c[101][101];
int Move[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

bool isRange(int y,int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

void fill(int y,int x)
{
	if (!isRange(y, x)|| c[y][x])
		return;
	c[y][x] = 1;

	for (int i = 0; i < 4; ++i)
	{
		int newy = y + Move[i][0];
		int newx = x + Move[i][1];
		fill(newy, newx);
	}
}

int searchMax()
{
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (c[i][j] == 0)
			{
				fill(i,j);
				++cnt;
			}
		}
	}
	return cnt;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];
	int cnt = 0;
	int max = 1;

	while (cnt != N * N)
	{
		bool isChanged = false;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				--arr[i][j];
				if (arr[i][j] == 0)
				{
					++cnt;
					isChanged = true;
					zero[i][j] = 1;
				}
			}
		}
		memcpy(c, zero, sizeof(zero));
		int temp = searchMax();
		if (max < temp)
			max = temp;
	}
	cout << max;
	return 0;
} 