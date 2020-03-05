#include <iostream>
#include<queue>
using namespace std;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
string c[101];
int N, M;

bool isRange(int y,int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M)
		return false;
	return true;
}

int bfs(int y, int x)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ { y,x },1 });
	c[y][x] = '0';
	int count;
	while (!q.empty())
	{
		int new_y = q.front().first.first;
		int new_x = q.front().first.second;
		count = q.front().second;
		q.pop();
		if (new_y == N - 1 && new_x == M - 1)
			return count;

		for (int direct = 0; direct < 4; ++direct)
		{
			int Ny = new_y + dy[direct], Nx = new_x + dx[direct];
			if (isRange(Ny,Nx)&&c[Ny][Nx]=='1')
			{
				c[Ny][Nx] = '0';
				q.push({{ Ny,Nx },count+1});
			}
		}
	}
}


int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> c[i];

	cout << bfs(0, 0);
	return 0;
}