//2964kb, 12ms
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[501][501];

int max_sum()
{
	int k = n - 1;
	while (k != 0)
	{
		for (int i = 0; i < k; ++i)
			arr[k - 1][i] += max(arr[k][i], arr[k][i + 1]);
		--k;
	}
	return arr[0][0];
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i + 1; ++j)
			cin >> arr[i][j];
	cout << max_sum();
	return 0;
}