#include <iostream>
#include<queue>
using namespace std;
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool arr[51][51] = { 0 };
int M, N, K;
bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	arr[i][j] = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && arr[ny][nx] == 1)
			{
				arr[ny][nx] = 0;
				q.push({ ny,nx });
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int a = 0; a < T; a++)
	{
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			int a, b; cin >> a >> b;
			arr[b][a] = 1;
		}
		int ret = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] == 1)
				{
					++ret;
					bfs(i, j);
				}
			}
		}
		cout << ret<<'\n';
	}
	
	return 0;
}