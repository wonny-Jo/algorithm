#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int arr[101];
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	int dp[10001];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[j] > i)
				break;
			if (dp[i - arr[j]] == -1) //불가능한경우
				continue;
			if (dp[i] == -1) //현재 위치의 횟수가 아직 정해지지 않은경우
				dp[i] = dp[i - arr[j]] + 1;
			else //현재와 이전 모두 횟수가 있으면 둘 중 최소값을 가진다.
				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		}
	}
	cout << dp[k] << '\n';

	return 0;
}
