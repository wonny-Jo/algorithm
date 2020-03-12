#include<iostream>
using namespace std;
int N;
int cnt[1000001] = { 0 };
int min(int a, int b)
{
	return a < b ? a : b;
}


int main()
{
	cin >> N;
	for (int i = 2; i <= N; ++i)
	{
		if (i % 3 == 0)
		{
			if (i % 2 == 0)
			{
				cnt[i] = min(cnt[i / 3], cnt[i / 2]);
				cnt[i] = min(cnt[i], cnt[i - 1]) + 1;
			}
			else
				cnt[i] = min(cnt[i - 1], cnt[i / 3]) + 1;
		}
		else 
		{
			if (i % 2 == 0)
				cnt[i] = min(cnt[i - 1], cnt[i / 2]) + 1;
			else
				cnt[i] = cnt[i - 1] + 1;
		}
	}
	cout << cnt[N];

	return 0;
}