#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };

bool c[51][51];
int M, N, K;
bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

void dfs(int y, int x)
{
	stack<pair<int, int>> s;
	s.push({ y,x });
	c[y][x] = 0;

	while (!s.empty())
	{
		int new_y = s.top().first;
		int new_x = s.top().second;
		s.pop();

		for (int direct= 0; direct < 4; ++direct)
		{
			int ny = new_y + dy[direct], nx = new_x + dx[direct];
			if (isRange(ny, nx) && c[ny][nx] == 1)
			{
				c[ny][nx] = 0;
				s.push({new_y, new_x });
				s.push({ ny, nx });
				break;
			}
		}
	}
}



int main()
{
	int T; cin >> T;
	int y, x;
	for (int i = 0; i < T; ++i)
	{
		memset(c, 0, sizeof(c));
		cin >> M >> N >> K;
		for (int j = 0; j < K; ++j)
		{
			cin >> x >> y;
			c[y][x] = 1;
		}
		int count = 0;
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (c[j][k] == 1)
				{
					dfs(j, k);
					++count;
				}
			}
		}
		cout << count << endl;
	}
	

	return 0;
}