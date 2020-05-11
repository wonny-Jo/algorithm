#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N;
int num[501][501];
int dp[501][501];

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

int dfs(int i, int j)
{
	int& ret = dp[i][j];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int k = 0; k < 4; k++)
	{
		int y = i + m[k][0];
		int x = j + m[k][1];
		if (isRange(y, x) && num[i][j] < num[y][x])
			ret = max(ret, dfs(y, x) + 1);
	}
	return ret;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> num[i][j];

	memset(dp, -1, sizeof(dp));
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (dp[i][j] == -1)
				ret = max(ret, dfs(i, j));
	cout << ret;
	return 0;
}
