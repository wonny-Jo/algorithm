#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool visit[101][101];
string s[101];
int N;
int col[101][101]; //R:0, B:1, G:2

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

void bfs(int i, int j, int n) //n은 분류기준 수
{
	visit[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });

	int color = col[i][j] % n;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && !visit[ny][nx] && col[ny][nx] % n == color)
			{
				visit[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	

	cin >>N;
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		for (int j = 0; j < N; j++)
		{
			if (s[i][j] == 'R')
				col[i][j] = 0;
			else if (s[i][j] == 'B')
				col[i][j] = 1;
			else
				col[i][j] = 2;
		}
	}

	memset(visit, 0, sizeof(visit));
	int cnt1 = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				++cnt1;
				bfs(i, j, 3);
			}
		}
	}
	memset(visit, 0, sizeof(visit));
	int cnt2 = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j])
			{
				++cnt2;
				bfs(i, j, 2);
			}
		}
	}
	cout << cnt1 << ' ' << cnt2;
	return 0;
}
