//393012kb, 36ms
#include<iostream>
#include<algorithm>
using namespace std;
int N, K;
int W[1001], V[1001];
int dp[1001][100001] = { 0 }; //i번째 물건까지, 무게합
							  //dp[i][j]=max(dp[i-1][j],dp[i-1][j-W[i]]+v[i])

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j - W[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
		}

	int ret = 0;
	for (int i = 1; i <= K; i++)
		ret = max(ret, dp[N][i]);
	cout << ret;
	return 0;
}
