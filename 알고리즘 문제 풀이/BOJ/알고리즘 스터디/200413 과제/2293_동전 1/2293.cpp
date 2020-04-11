#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int ret[10001] = { 0 };
int temp[10001] = { 0 };
//ret[k]=ret[k-coin]+temp[k]

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	int coin[101];
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> coin[i];
	sort(coin, coin + n);

	for (int j = 0; j < n; ++j)
	{
		for (int i = 1; i <= k; ++i)
		{
			if (coin[j] > i)
				ret[i] = temp[i];
			else
				ret[i] = ret[i - coin[j]] + temp[i];
			if (coin[j] == i)
				++ret[i];
		}
		memcpy(temp, ret, sizeof(ret));
	}

	cout << ret[k];

	return 0;
}