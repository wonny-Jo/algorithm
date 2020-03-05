#include<iostream>
#include<queue>
using namespace std;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int M, N;
int board[1001][1001];

int max(int a, int b)
{
	return a > b ? a : b;
}

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

int main()
{
	queue<pair<pair<int, int>, int>> q;
	cin >> M >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] > 0)
				q.push({ {i,j},0 });
		}

	int result = 0;
	while (!q.empty())
	{
		int new_y = q.front().first.first;
		int new_x = q.front().first.second;
		int count = q.front().second;
		q.pop();
		result = max(result, count);

		for (int direct = 0; direct < 4; ++direct)
		{
			int Ny = new_y + dy[direct], Nx = new_x + dx[direct];
			if (isRange(Ny, Nx) && board[Ny][Nx] == 0)
			{
				q.push({ {Ny,Nx},count + 1 });
				board[Ny][Nx] = 1;
			}
		}
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}

	cout << result;
	return 0;
}