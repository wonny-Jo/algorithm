#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
bool board[301][301];
int direct[8][2] = { {1,-2},{2,-1},{2,1},{1,2},{-1,-2},{-2,-1},{-1,2},{-2,1} };
int N, goal[2];

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

int bfs(int y,int x)
{
	board[y][x] = 1;
	queue<pair<pair<int, int>,int>> q;
	int cnt = 0;
	q.push({ { y,x },0 });

	while (!q.empty())
	{
		int ny = q.front().first.first;
		int nx = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (ny == goal[0] && nx == goal[1])
			return cnt;

		for (int i = 0; i < 8; i++)
		{
			int newY = ny + direct[i][0];
			int newX = nx + direct[i][1];
			if (isRange(newY, newX) && !board[newY][newX])
			{
				board[newY][newX] = 1;
				q.push({ { newY,newX },cnt + 1 });
			}
		}
	}
	return -1;
}


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int start[2];
		cin >> start[0] >> start[1] >> goal[0] >> goal[1];
		memset(board, 0, sizeof(board));
		cout<<bfs(start[0], start[1])<<'\n';
	}
	

	return 0;
}