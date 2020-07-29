//1988kb, 0ms
#include<iostream>
#include<algorithm>
using namespace std;
int cache[1001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int arr[1001];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	cache[0] = arr[0];
	int size = 0;
	for (int i = 1; i < N; ++i)
	{
		if (cache[size] < arr[i])
		{
			++size;
			cache[size] = arr[i];
		}
		else
		{
			int index = lower_bound(cache, cache + size, arr[i]) - cache;
			cache[index] = arr[i];
		}
	}
	cout << size + 1;
	return 0;
}