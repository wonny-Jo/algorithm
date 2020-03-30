#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int N;
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
	queue<pair<int, int>> q;
	q.push({ y,x });
	c[y][x] = 1;

	while (!q.empty())
	{
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int newy = ny + Move[i][0];
			int newx = nx + Move[i][1];
			if (isRange(newy, newx)&&!c[newy][newx])
			{
				c[newy][newx] = 1;
				q.push({ newy,newx });
			}

		}
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
	bool zero[101][101] = { 0 };
	int arr[101][101];
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