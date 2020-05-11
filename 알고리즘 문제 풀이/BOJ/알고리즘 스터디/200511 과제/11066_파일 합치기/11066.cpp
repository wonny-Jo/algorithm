#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	for (int a = 0; a < T; a++)
	{
		int K; cin >> K;
		int dp[501][501] = { 0 };
		int fileNum[501];
		for (int i = 0; i < K; i++)
			cin >> fileNum[i];
		
		for (int i = 1; i < K; i++)
		{
			for (int j = 0; j < K-i; j++)
			{
				dp[j][j + i] = dp[j][j] + dp[j + 1][j + i];
				for (int k = 1; k < i; k++)
					dp[j][j + i] = min(dp[j][j+i],dp[j][j + k] + dp[j + k + 1][j + i]);
				
				for (int k = j; k <= j+i; k++)
					dp[j][j + i] += fileNum[k];
			}
		}
		cout << dp[0][K - 1] << '\n';

	}




	return 0;
}