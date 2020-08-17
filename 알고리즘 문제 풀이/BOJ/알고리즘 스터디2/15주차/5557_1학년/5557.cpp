#include<iostream>
#include<string.h>
using namespace std;
long long N, arr[100], answer;
long long dp[21][101];
long long solve(long long sum, int i)
{
	if (sum < 0 || sum>20)
		return 0;
	if (dp[sum][i] != -1)
		return dp[sum][i];
	if (i == N)
	{
		if (sum == answer)
			return 1;
		return 0;
	}
	return dp[sum][i] = solve(sum + arr[i], i + 1) + solve(sum - arr[i], i + 1);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N; --N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> answer;
	memset(dp, -1, sizeof(dp));
	cout<<solve(arr[0],1);
	return 0;
}