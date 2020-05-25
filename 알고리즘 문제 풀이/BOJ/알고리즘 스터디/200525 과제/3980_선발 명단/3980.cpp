#include<iostream>
#include<algorithm>
using namespace std;
int arr[12][12];

int dfs(bool c[11],int cnt,int sum)
{
	if (cnt == 11)
		return sum;

	int ret = 0;
	for (int i = 0; i < 11; i++)
	{
		if (c[i] || arr[cnt][i] == 0)
			continue;
		c[i] = 1;
		ret = max(ret, dfs(c, cnt + 1, sum + arr[cnt][i]));
		c[i] = 0;
	}
	return ret;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> arr[i][j];
		bool c[11] = { 0 };
		cout << dfs(c, 0, 0) << '\n';
	}
	return 0;
}