#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAX 1000000000 + 1
int N, M, K;
string ret;
int dp[101][101];

int combination(int A_num, int Z_num)
{
	if (A_num == 0 || Z_num == 0)
		return 1;
	int& ret = dp[A_num][Z_num];
	if (ret != -1)
		return ret;

	ret = min(combination(A_num - 1, Z_num) + combination(A_num, Z_num - 1), MAX);
	return ret;
}

void findWord(int A_num, int Z_num, int num)
{
	if (A_num == 0)
	{
		for (int i = 0; i < Z_num; i++)
			ret += 'z';
		return;
	}
	if (Z_num == 0)
	{
		for (int i = 0; i < A_num; i++)
			ret += 'a';
		return;
	}

	int temp = combination(A_num - 1, Z_num);
	if (num < temp)
	{
		ret += 'a';
		findWord(A_num - 1, Z_num, num);
	}
	else
	{
		ret += 'z';
		findWord(A_num, Z_num - 1, num - temp);
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M >> K;
	memset(dp, -1, sizeof(dp));

	if (K > combination(N, M))
		cout << -1;
	else
	{
		findWord(N, M, K - 1);
		cout << ret;
	}

	return 0;
}