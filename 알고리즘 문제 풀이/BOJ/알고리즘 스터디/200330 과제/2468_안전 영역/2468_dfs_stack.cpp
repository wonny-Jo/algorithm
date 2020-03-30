#include<iostream>
#include<stack>
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
	stack<pair<int, int>> s;
	s.push({ y,x });
	c[y][x] = 1;

	while (!s.empty())
	{
		int ny = s.top().first;
		int nx = s.top().second;
		s.pop();

		for (int i = 0; i < 4; ++i)
		{
			int newy = ny + Move[i][0];
			int newx = nx + Move[i][1];
			if (isRange(newy, newx) && !c[newy][newx])
			{
				c[newy][newx] = 1;
				s.push({ ny, nx });
				s.push({ newy,newx });
				break;
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