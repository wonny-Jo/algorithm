#include <iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
string s[21];
vector<pair<int, int>> v;
int w, h, cnt;
bool visit[21][21], c[11];
int dist[11][11];
int start[2], ret;
bool isRange(int y, int x)
{
	if (y < 0 || y >= h || x < 0 || x >= w)
		return false;
	return true;
}

void bfs(int i, int j,int num)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ {i,j},0 });
	visit[i][j] = 1;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && s[ny][nx] != 'x' && !visit[ny][nx])
			{
				if (s[ny][nx] == '*')
					for (int j = 0; j < v.size(); j++)
						if (v[j].first == ny && v[j].second == nx)
							dist[num][j] = cnt + 1;
				visit[ny][nx] = 1;
				q.push({ {ny,nx},cnt + 1 });
			}
		}
	}
}

void dfs(int cur, int cnt, int num)
{
	if (cnt == v.size())
	{	
		ret = min(ret, num);
		return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (!c[i]&&dist[cur][i]!=-1)
		{
			c[i] = 1;
			dfs(i, cnt + 1, num + dist[cur][i]);
			c[i] = 0;
		}
	}
}

int solve()
{
	int startNum;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < v.size(); i++)
	{
		memset(visit, 0, sizeof(visit));
		bfs(v[i].first, v[i].second, i);
		if (v[i].first == start[0] && v[i].second == start[1])
			startNum = i;
	}

	memset(c, 0, sizeof(c));
	c[startNum] = 1;
	ret = 40000;
	dfs(startNum, 1, 0);
	if (ret == 40000)
		return -1;
	else
		return ret;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		cnt = 0;
		vector<pair<int, int>> temp;
		for (int i = 0; i < h; i++)
		{
			cin >> s[i];
			for (int j = 0; j < w; j++)
			{
				if (s[i][j] == 'o')
				{
					temp.push_back({ i,j });
					start[0] = i, start[1] = j;
				}
				if (s[i][j] == '*')
					temp.push_back({ i,j });
			}
		}
		v = temp;
		cout << solve() << '\n';
	}
	return 0;
}
