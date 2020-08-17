#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[1001], dp[1001] = { 0 };

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	dp[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		dp[i] = arr[i];
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
	}

	int ret = 0;
	for (int i = 0; i < N; i++)
		ret = max(ret, dp[i]);
	cout << ret;
	return 0;
}
