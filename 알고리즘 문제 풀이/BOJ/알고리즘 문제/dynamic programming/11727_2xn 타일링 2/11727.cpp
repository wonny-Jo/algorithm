//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

long long cache[1001];

//f(2k+1) = f(2k) - 1
//f(2k) = f(2k-1) + 1
long long countTile(int n)
{
	if (n == 1)
		return 1;

	long long& ret = cache[n];
	if (ret != -1)
		return ret;

	if (n % 2 == 1)
		return ret = (2 * countTile(n - 1) - 1) % 10007;
	else
		return ret = (2 * countTile(n - 1) + 1) % 10007;
}


int main()
{
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << countTile(n) << endl;
	return 0;
}