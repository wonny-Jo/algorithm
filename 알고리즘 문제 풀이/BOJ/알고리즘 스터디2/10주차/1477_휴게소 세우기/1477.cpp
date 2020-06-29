#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, L; cin >> N >> M >> L;
	int arr[103];
	arr[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	arr[N + 1] = L;
	int startDist = 1, endDist = L;
	while (startDist <= endDist)
	{
		int midDist = (startDist + endDist) / 2;
		int cnt = 0;
		for (int i = 0; i <= N; ++i)
		{
			cnt += (arr[i + 1] - arr[i]) / midDist;
			if ((arr[i + 1] - arr[i]) % midDist == 0)
				--cnt;
		}
		if (cnt > M)
			startDist = midDist + 1;
		else
			endDist = midDist - 1;
	}
	cout << startDist;

	return 0;
}