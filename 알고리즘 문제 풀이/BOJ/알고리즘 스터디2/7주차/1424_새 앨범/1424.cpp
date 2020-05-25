#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	int N, L, C; cin >> N >> L >> C;
	int num = C / (L + 1);
	if (C % (L + 1) == L)
		++num;
	if (num % 13 == 0)
		--num;

	int ret = N / num;
	if (N % num != 0)
		++ret;
	cout << ret;

	return 0;
}