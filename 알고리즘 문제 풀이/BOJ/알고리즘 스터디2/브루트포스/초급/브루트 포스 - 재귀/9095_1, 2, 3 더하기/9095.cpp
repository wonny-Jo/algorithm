#include<iostream>
#include<string.h>
using namespace std;
int cache[12];

// f(x)=f(x-1)+f(x-2)+f(x-3)
int countCase(int n)
{
	int& ret = cache[n];
	if (n == 1)
		return ret = 1;
	if (n == 2)
		return ret = 2;
	if (n == 3)
		return ret = 4;

	if (ret != -1)
		return ret;

	return ret = countCase(n - 1) + countCase(n - 2) + countCase(n - 3);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		cout << countCase(n) << endl;
	}
	return 0;
}