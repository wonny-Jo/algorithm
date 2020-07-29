//1992kb, 0ms
#include<iostream>
using namespace std;
int N;
long long cnt[101][10] = { 0 };

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cnt[1][0] = 0;
	for (int i = 1; i < 10; ++i)
		cnt[1][i] = 1;

	for (int i = 2; i <= N; ++i)
	{
		cnt[i][0] = cnt[i - 1][1];
		for (int j = 1; j < 9; ++j)
			cnt[i][j] = (cnt[i - 1][j - 1] + cnt[i - 1][j + 1]) % 1000000000;
		cnt[i][9] = cnt[i - 1][8];

	}
	long long sum = 0;
	for (int i = 0; i < 10; ++i)
		sum += cnt[N][i];
	cout << sum % 1000000000;

	return 0;
}