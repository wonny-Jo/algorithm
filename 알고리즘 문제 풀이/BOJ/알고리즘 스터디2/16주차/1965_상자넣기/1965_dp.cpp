#include<iostream>
#include<algorithm>
using namespace std;
int box[1001], dp[1001] = { 0 };

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> box[i];
	
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (box[i] > box[j])
				dp[i] = max(dp[i], dp[j] + 1);
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
		ret = max(ret, dp[i]);
	cout << ret;
	return 0;
}
