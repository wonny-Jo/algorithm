#include <iostream>
#include <queue>
using namespace std;
string s[1001];
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int w, h;

bool isRange(int y, int x)
{
	if (y < 0 || y >= h || x < 0 || x >= w)
		return false;
	return true;
}

int solve(queue<pair<int, int>> sg_q, queue<pair<int, int>> fire_q)
{
	int ret = 1;
	while (1)
	{
		queue<pair<int, int>> sg_nq, fire_nq;
		while (!fire_q.empty())
		{
			int y = fire_q.front().first;
			int x = fire_q.front().second;
			fire_q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + m[i][0];
				int nx = x + m[i][1];
				if (isRange(ny, nx) && s[ny][nx] != '#' && s[ny][nx] != '*')
				{
					s[ny][nx] = '*';
					fire_nq.push({ ny,nx });
				}
			}
		}
		fire_q = fire_nq;


		while (!sg_q.empty())
		{
			int y = sg_q.front().first;
			int x = sg_q.front().second;
			sg_q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + m[i][0];
				int nx = x + m[i][1];
				if (!isRange(ny, nx))
					return ret;
				if (s[ny][nx] == '.')
				{
					s[ny][nx] = '@';
					sg_nq.push({ ny,nx });
				}
			}
		}
		if (sg_nq.empty())
			return -1;
		sg_q = sg_nq;
		++ret;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	for (int a = 0; a < t; a++)
	{
		cin >> w >> h;
		queue<pair<int, int>> sg_q, fire_q;
		for (int i = 0; i < h; i++)
		{
			cin >> s[i];
			for (int j = 0; j < w; j++)
			{
				if (s[i][j] == '@')
					sg_q.push({ i,j });
				if (s[i][j] == '*')
					fire_q.push({ i,j });
			}
		}
		int ret = solve(sg_q,fire_q);
		if (ret == -1)
			cout << "IMPOSSIBLE"<<'\n';
		else
			cout << ret<<'\n';
	}
	return 0;
}
