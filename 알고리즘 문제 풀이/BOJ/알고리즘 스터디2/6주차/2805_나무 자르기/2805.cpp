#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	int low = 0, high = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (high < arr[i])
			high = arr[i];
	}

	int ret = 0;
	while (low <= high)
	{	
		int mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
			if (mid < arr[i])
				sum += arr[i] - mid;
		
		if (sum >= M)
		{
			if (ret < mid)
				ret = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << ret << '\n';
	return 0;
}