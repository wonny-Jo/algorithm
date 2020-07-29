//1984kb, 0ms
#include<iostream>
#include<string.h>
using namespace std;
long long result[91];

long long fibonacci(int num)
{
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;

	long long &ret = result[num];
	if (ret != -1)
		return ret;
	return ret = fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	memset(result, -1, sizeof(result));
	cout << fibonacci(n);

	return 0;
}