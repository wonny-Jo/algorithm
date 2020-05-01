#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int arr[1002][1002];
int dp[1002][1002] = { 0 };
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];

	cout << dp[N][M];

	return 0;
}
