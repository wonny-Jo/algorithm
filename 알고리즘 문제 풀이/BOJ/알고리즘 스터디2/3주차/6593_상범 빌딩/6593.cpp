#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int d[6][3] = { {0,0,1},{0,0,-1},{0,1,0},{0,-1,0}, {1,0,0},{-1,0,0} };
int L, R, C;
string s[31][31];
bool visit[31][31][31];
int ret;
int start[3], goal[3];

bool isRange(int z, int y, int x)
{
	if (z < 0 || z >= L || y < 0 || y >= R || x < 0 || x >= C)
		return false;
	return true;
}

bool bfs(int i, int j, int k)
{
	visit[i][j][k] = 1;
	queue<pair<pair<int, int>, pair<int, int>>> q; //i,j,k,cnt
	q.push({ {i,j},{k,0} });

	while (!q.empty())
	{
		int z = q.front().first.first;
		int y = q.front().first.second;
		int x = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (z == goal[0] && y == goal[1] && x == goal[2])
		{
			ret = cnt;
			return true;
		}

		for (int i = 0; i < 6; i++)
		{
			int nz = z + d[i][0];
			int ny = y + d[i][1];
			int nx = x + d[i][2];
			if (isRange(nz, ny, nx) && s[nz][ny][nx] != '#' && !visit[nz][ny][nx])
			{
				visit[nz][ny][nx] = 1;
				q.push({ {nz,ny},{nx,cnt + 1} });
			}
		}
	}
	return false;
}



int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	cin >> L >> R >> C;
	while (L != 0 || R != 0 || C != 0)
	{
		for (int i = 0; i < L; i++)
			for (int j = 0; j < R; j++)
			{
				cin >> s[i][j];
				for (int k = 0; k < C; k++)
				{
					if (s[i][j][k] == 'S')
					{
						start[0] = i;
						start[1] = j;
						start[2] = k;
					}
					else if (s[i][j][k] == 'E')
					{
						goal[0] = i;
						goal[1] = j;
						goal[2] = k;
					}
				}
			}

		memset(visit, 0, sizeof(visit));
		ret = 10000;
		if (bfs(start[0], start[1], start[2]))
			cout << "Escaped in " << ret << " minute(s)." << '\n';
		else
			cout << "Trapped!" << '\n';

		cin >> L >> R >> C;
	}

	return 0;
}
