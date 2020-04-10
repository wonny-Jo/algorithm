#include<iostream>
#include<algorithm>
using namespace std;
int N, M, H;
int line[32][12] = { 0 };//0: 연결x, 1:오른쪽으로 연결, 2:왼쪽으로 연결

bool isPossible()
{
	for (int i = 1; i <= N; ++i)
	{
		int pos = i;
		for (int j = 1; j <= H; ++j)
		{
			if (line[j][pos] == 1)
				++pos;
			else if (line[j][pos] == 2)
				--pos;
		}
		if (pos != i)
			return false;
	}
	return true;
}

int dfs(int cnt, int row, int col)
{
	if (cnt > 3)
		return cnt;
	if (isPossible())
		return cnt;

	int ret = 4;

	int i = row, j = col;
	while (i <= H)
	{
		while (j < N)
		{
			if (line[i][j] == 0 && line[i][j + 1] == 0)
			{
				line[i][j] = 1;
				line[i][j + 1] = 2;
				ret = min(ret, dfs(cnt + 1, i, j + 2));
				line[i][j] = 0;
				line[i][j + 1] = 0;
				++j;
			}

			else if (line[i][j] == 2)
				++j;
			else if (line[i][j] == 1)
				j += 2;
			else //line[i][j]==1
				j += 3;
		}
		if (j >= N)
			j = 1;
		++i;
	}

	return ret;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		line[a][b] = 1;
		line[a][b+1] = 2;
	}
	int ret=dfs(0,1,1);
	if (ret > 3)
		cout << -1;
	else
		cout << ret;


	return 0;
}