#include<iostream>
using namespace std;
string dp[16];


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	dp[0] = "{}";
	for (int i = 1; i <= 15; i++)
	{
		dp[i] = '{';
		for (int j = 0; j < i; j++)
		{
			dp[i] += dp[j];
			dp[i] += ',';
		}
		dp[i][dp[i].size() - 1] = '}';
	}

	int t; cin >> t;
	for (int i = 0; i < t; ++i)
	{
		string s1, s2; cin >> s1 >> s2;
		int num1, num2;
		for (int i = 0; i <= 15; i++)
		{
			if (dp[i] == s1) num1 = i;
			if (dp[i] == s2) num2 = i;
		}
		cout << dp[num1 + num2]<<'\n';
	}

	return 0;
}
