#include<iostream>
#include<algorithm>
using namespace std;
long long T[100001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long N, M; cin >> N >> M;
	for (long long i = 0; i < N; i++)
		cin >> T[i];

	sort(T, T + N);
	long long low = 1, high = M * T[N - 1];
	long long result = M * T[N - 1];
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		
		long long cnt = 0;
		for (int i = 0; i < N; i++)
			cnt += mid / T[i];

		if (cnt<M)
			low = mid + 1;
		else
		{
			high = mid - 1;
			result = min(result,mid);
		}
	}
	cout << result;
	return 0;
}