#include<iostream>
#include<algorithm>
using namespace std;
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int R, C;
string s[21];
bool c[27] = { 0 };
bool visit[21][21] = { 0 };
int ret = 0;

bool isRange(int y, int x)
{
	if (y < 0 || y >= R || x < 0 || x >= C)
		return false;
	return true;
}

void dfs(int y, int x, int cnt)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + direction[i][0];
		int nx = x + direction[i][1];
		if (isRange(ny, nx) && !visit[ny][nx]&&!c[s[ny][nx]-'A'])
		{
			c[s[ny][nx] - 'A'] = 1;
			visit[ny][nx] = 1;
			dfs(ny, nx, cnt + 1);
			visit[ny][nx] = 0;
			c[s[ny][nx] - 'A'] = 0;
		}
	}

	ret = max(ret, cnt);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; ++i)
		cin >> s[i];

	visit[0][0] = 1;
	c[s[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ret;
	return 0;
}