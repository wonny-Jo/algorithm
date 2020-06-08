#include<iostream> 
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int n;
double route[16][16];
double dp[16][1 << 16];

double dfs(int currentCity, int bit)
{
	double& ret = dp[currentCity][bit];
	if (ret != 0)
		return ret;

	if (bit == (1 << n) - 1)
	{
		if (route[currentCity][0] != 0)
			return route[currentCity][0];
		else
			return 1000000000;
	}

	ret = 1000000000;
	for (int i = 0; i < n; i++)
	{
		if (route[currentCity][i] && !(bit & (1 << i)))
		{
			int visit = bit | (1 << i);
			ret = min(ret, dfs(i, visit) + route[currentCity][i]);
		}
	}
	return ret;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int arr[16][2];
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			route[i][j] = sqrt(pow(arr[i][0] - arr[j][0], 2) + pow(arr[i][1] - arr[j][1], 2));
	memset(dp, 0, sizeof(dp));
	cout.precision(6);
	cout << fixed << dfs(0, 1);
	return 0;
}
