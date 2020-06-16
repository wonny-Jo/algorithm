#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int d[501][501] = { 0 };

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = 501;
		}
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		d[a][b] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				d[i][j] = min(d[i][k] + d[k][j],d[i][j]);
	
	int ret = 0;
	for (int i = 1; i <= N; i++)
	{
		++ret;
		for (int j = 1; j <= N; j++)
		{
			if (d[i][j] == 501&&d[j][i]==501)
			{
				--ret;
				break;
			}
		}
	}
	cout << ret;
	return 0;
}