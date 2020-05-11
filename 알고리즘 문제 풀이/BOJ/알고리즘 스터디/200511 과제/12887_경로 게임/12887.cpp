#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int m[3][2] = { {-1,0},{1,0},{0,1} };//왼쪽으로 가는 움직임은 필요없다.
int M;
bool init[2][51] = { 0 };
bool visit[2][51];

bool isRange(int y, int x)
{
	if (y < 0 || y >= 2 || x < 0 || x >= M)
		return false;
	return true;
}

int bfs(int i, int j)
{
	visit[i][j] = 1;
	queue<pair<pair<int, int>,int>> q;
	q.push({ { i,j },1 });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (x == M - 1)
			return cnt;

		for (int i = 0; i < 3; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && !visit[ny][nx])
			{
				visit[ny][nx] = 1;
				q.push({ {ny,nx},cnt + 1 });
			}
		}
	}

}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> M;
	string s;
	int whiteNum = 0; //흰색의 갯수
	for (int i = 0; i < 2; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			if (s[j] == '#')
				init[i][j] = 1;
			else
				++whiteNum;
		}
	}

	int ret = 100;
	for (int i = 0; i < 2; i++)
	{
		memcpy(visit, init, sizeof(init));
		if (visit[i][0] == 0)
			ret=min(ret,bfs(i, 0));
	}
	cout << whiteNum - ret;
	return 0;
}
