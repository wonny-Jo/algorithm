#include<iostream>
#include<algorithm>
using namespace std;
int arr[200001];
int N, C;

//위치 인덱스가 아닌 거리를 기준으로 이분탐색을 진행하자.
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);
	int startDist = 1, endDist = arr[N - 1] - arr[0];
	int maxCnt = 0;
	while (startDist <= endDist)
	{
		int midDist = (endDist + startDist) / 2;

		int first = arr[0];
		int cnt = 1;
		for (int i = 1; i < N; ++i)
		{
			if (arr[i] - first >= midDist)
			{
				++cnt;
				first = arr[i];
			}
		}
		if (cnt >= C)
		{
			maxCnt = max(maxCnt, midDist);
			startDist = midDist + 1;
		}
		else
			endDist = midDist - 1;
	}
	cout << maxCnt;
	return 0;
}