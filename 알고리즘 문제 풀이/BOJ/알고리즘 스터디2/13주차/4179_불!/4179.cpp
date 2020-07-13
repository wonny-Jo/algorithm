#include <iostream>
#include <queue>
using namespace std;
string s[1001];
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int R, C;

bool isRange(int y, int x)
{
	if (y < 0 || y >= R || x < 0 || x >= C)
		return false;
	return true;
}

int solve(queue<pair<int, int>> jh_q, queue<pair<int, int>> fire_q)
{
	int ret = 1;
	while (1)
	{
		queue<pair<int, int>> jh_nq, fire_nq;
		while (!fire_q.empty())
		{
			int y = fire_q.front().first;
			int x = fire_q.front().second;
			fire_q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + m[i][0];
				int nx = x + m[i][1];
				if (isRange(ny, nx) && s[ny][nx] != '#' && s[ny][nx] != 'F')
				{
					s[ny][nx] = 'F';
					fire_nq.push({ ny,nx });
				}
			}
		}
		fire_q = fire_nq;


		while (!jh_q.empty())
		{
			int y = jh_q.front().first;
			int x = jh_q.front().second;
			jh_q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + m[i][0];
				int nx = x + m[i][1];
				if (!isRange(ny, nx))
					return ret;
				if (s[ny][nx] == '.')
				{
					s[ny][nx] = 'J';
					jh_nq.push({ ny,nx });
				}
			}
		}
		if (jh_nq.empty())
			return -1;
		jh_q = jh_nq;
		++ret;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	queue<pair<int, int>> jh_q, fire_q;
	for (int i = 0; i < R; i++)
	{
		cin >> s[i];
		for (int j = 0; j < C; j++)
		{
			if (s[i][j] == 'J')
				jh_q.push({ i,j });
			if (s[i][j] == 'F')
				fire_q.push({ i,j });
		}
	}
	int ret = solve(jh_q,fire_q);
	if (ret == -1)
		cout << "IMPOSSIBLE";
	else
		cout << ret;
	return 0;
}
