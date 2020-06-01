#include<iostream>
using namespace std;
long long dp[101][101] = { 0 }; //선택한 노래수, 노래종류수

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	int N, M, P; cin >> N >> M >> P;

	dp[0][0] = 1;
	for (int i = 1; i <= P; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (N - j + 1)) % 1000000007;
			if (j > M)
				dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - M)) % 1000000007;
		}
	}
	cout << dp[P][N];
	return 0;
}