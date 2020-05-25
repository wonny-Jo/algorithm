#include<iostream>
#include<algorithm>
using namespace std;
int arr1[16000000], arr2[16000000];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int a[4000], b[4000], c[4000], d[4000];
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr1[i * n + j] = a[i] + b[j];
			arr2[i * n + j] = c[i] + d[j];
		}
	}
	sort(arr1, arr1 + n * n);
	sort(arr2, arr2 + n * n);
	long long sum = 0;
	int idx = n * n - 1;
	int cnt = 0;
	for (int i = 0; i < n * n; i++)
	{
		if (i != 0 && arr1[i] == arr1[i - 1])
		{
			sum += cnt;
			continue;
		}
		cnt = 0;
		int key = -arr1[i];
		while (idx >= 0 && key <= arr2[idx])
		{
			if (key == arr2[idx])
				++cnt;
			--idx;
		}
		sum += cnt;
	}
	cout << sum;
	return 0;
}