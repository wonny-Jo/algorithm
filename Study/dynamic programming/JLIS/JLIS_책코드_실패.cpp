#include<iostream>
using namespace std;

int cache[101][101];
int A_len, B_len, A[101], B[101];

int max(int a, int b)
{
	return a > b ? a : b;
}
int jlis(int A_start,int B_start)
{
	int& ret = cache[A_start][B_start];
	if (ret != -1)
		return ret;
	ret = 2;
	int maxElement = max(A[A_start], B[B_start]);
	for (int i = A_start+1; i < A_len; ++i)
	{
		if (maxElement < A[i])
			ret = max(ret, jlis(i, B_start) + 1);
	}
	for (int i = B_start + 1; i < B_len; ++i)
	{
		if (maxElement < B[i])
			ret = max(ret, jlis(A_start, i) + 1);
	}
	return ret;
}

int main()
{
	int C; 
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		cin >> A_len >> B_len;
		for (int j = 0; j < A_len; ++j)
			cin >> A[j];
		for (int j = 0; j < B_len; ++j)
			cin >> B[j];
		memset(cache, -1, sizeof(cache));
		cout << jlis(0, 0) << endl;

	}

	return 0;
}