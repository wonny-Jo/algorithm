#include<iostream>
using namespace std;
int M, N;
int ret[501][501] = { 0 };
int h[501][501];
int direction[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

bool isRange(int y, int x)
{
	if (y >= M || y < 0 || x >= N || x < 0)
		return false;
	return true;
}

int dfs(int y, int x)
{
	if (!isRange(y,x))
		return 0;
	if (y == M - 1 && x == N - 1)
		return 1;

	int cnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + direction[i][0];
		int nx = x + direction[i][1];
		if(h[ny][nx]<h[y][x])
			cnt += dfs(ny, nx);
	}

	return cnt;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	cin >> M>> N;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> h[i][j];
	
	cout << dfs(0, 0);

	return 0;
}