#include<iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
	int N; cin >> N;
	int connect[40001];
	int cnt[40001];
	for (int i = 1; i <= N; ++i)
	{
		cin >> connect[i];
		cnt[i] = 1;
	}
	int max_count = 1;
	for (int i = 2; i <= N; ++i)
	{
		for (int j = i-1; j > 0; --j)
		{
			if (connect[i] > connect[j] && cnt[i] <= cnt[j])
				cnt[i] = cnt[j] + 1;
		}
		max_count = max(max_count, cnt[i]);
	}
	cout << max_count;


	return 0;
}