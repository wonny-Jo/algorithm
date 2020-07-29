//1984kb, 4ms
#include<iostream>
#include<string.h>
using namespace std;
long long result[101];

long long fibonacci(int num)
{
	if (num == 1 || num == 2 || num == 3)
		return 1;
	if (num == 4 || num == 5)
		return 2;

	long long& ret = result[num];
	if (ret != -1)
		return ret;

	return ret = fibonacci(num - 1) + fibonacci(num - 5);
}


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		memset(result, -1, sizeof(result));
		cout << fibonacci(N) << endl;
	}

	return 0;
}