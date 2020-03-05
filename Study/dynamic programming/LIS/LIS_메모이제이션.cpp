#include<iostream>
using namespace std;
#include<vector>

int n;
int cache[100], S[100];

int max(int a, int b)
{
	return a > b ? a : b;
}

int lis(int start)
{
	int& ret = cache[start];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = start+1; i < n; ++i)
	{
		if (S[start] < S[i])
			ret = max(ret, lis(i) + 1);
	}
	return ret;
}

int main()
{
	

	return 0;
}