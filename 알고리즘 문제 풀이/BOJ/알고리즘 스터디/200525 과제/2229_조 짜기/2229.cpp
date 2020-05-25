#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int N;
int arr[1001];
int dp[1001];

int solve(int i)
{
	if (i == N)
		return 0;

	int& ret = dp[i];
	if (ret != -1)
		return ret;

	ret = 0;
	int minNum = 10001, maxNum = 0;
	for (int j = i; j < N; j++)
	{
		minNum = min(minNum, arr[j]); 
		maxNum = max(maxNum, arr[j]);
		ret = max(ret, maxNum - minNum + solve(j + 1));
	}
	return ret;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0);

	return 0;
}