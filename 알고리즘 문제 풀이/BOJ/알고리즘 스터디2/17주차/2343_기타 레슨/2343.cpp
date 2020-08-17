#include<iostream>
#include<algorithm>
using namespace std;
int time[100001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	int high = 0, low = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> time[i];
		high += time[i];
		low = max(low, time[i]);
	}

	int result;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int temp = mid;
		int cnt = 1;

		for (int i = 0; i < N; i++)
		{
			if (temp < time[i])
			{
				++cnt;
				temp = mid;
			}
			temp -= time[i];
		}
		if (cnt > M)
			low = mid + 1;
		else
		{
			high = mid - 1;
			result = mid;
		}
	}
	cout << result;
	return 0;
}