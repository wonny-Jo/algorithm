#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K; cin >> N >> K;
	int low = 1, high = K;
	int ret;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; i++) 
			cnt += min(mid / i, N);
		if (cnt < K)
			low = mid + 1;
		else
		{
			high = mid - 1;
			ret = mid;
		}
	}
	cout << ret;
	return 0;
}