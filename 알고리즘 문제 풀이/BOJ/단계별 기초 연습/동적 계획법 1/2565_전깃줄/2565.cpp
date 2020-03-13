#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int N; cin >> N;
	int num[501] = { 0 };
	int a;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		cin >> num[a];
	}
	int cache[101] = { 0 };
	int size = 0;
	for (int i = 1; i <= 500; ++i)
	{
		if (num[i] == 0)
			continue;
		if (cache[size] < num[i])
		{
			++size;
			cache[size] = num[i];
		}
		else
		{
			int index = lower_bound(cache + 1, cache + 1 + size, num[i])-cache;
			cache[index] = num[i];
		}
	}
	cout << N - size;

	return 0;
}