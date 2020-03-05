#include<iostream>
using namespace std;
#include<algorithm>

int cache[201];
int A_len, B_len, S[201];

int max(int a, int b)
{
	return a > b ? a : b;
}
int jlis(int start)
{
	int& ret = cache[start];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = start+1; i < A_len+B_len; ++i)
	{
		if (S[start] < S[i])
			ret = max(ret, jlis(i) + 1);
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
		for (int j = 0; j < A_len+B_len; ++j)
			cin >> S[j];
		sort(S, S + A_len + B_len);
		memset(cache, -1, sizeof(cache));
		cout << jlis(0) << endl;

	}

	return 0;
}