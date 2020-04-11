#include<iostream>
#include<algorithm>
using namespace std;
int ret[10001][101] = { 0 }; //[k][n] 
//ret[k][n]=ret[k-coin[n]][n]+ret[k][n-1]
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	int coin[101];
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> coin[i];
	sort(coin+1, coin + n+1);

	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= n; j++)
		{
			if (coin[j] > i)
				ret[i][j] = ret[i][j - 1];
			else
				ret[i][j] = ret[i - coin[j]][j] + ret[i][j - 1];
			if (coin[j] == i)
				++ret[i][j];
		}
	}
	cout << ret[k][n];

	return 0;
}