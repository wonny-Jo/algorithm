#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int dp[100001][5][5];
int K;

int dfs(int N, int left, int right) 
{
	if (N == K)
		return 0;
	int& ret = dp[N][left][right];
	if (ret != 0)
		return ret;

	ret = 500000;

	int next = arr[N];
	if (next == left)
		ret = min(dfs(N + 1, left, right) + 1, ret);
	else if (next != right)
	{
		if (left == 0)
			ret = min(dfs(N + 1, next, right) + 2, ret);
		else
		{
			if (abs(left - next) == 1 || abs(left - next) == 3)
				ret = min(dfs(N + 1, next, right) + 3, ret);
			else
				ret = min(dfs(N + 1, next, right) + 4, ret);
		}
	}
	//오른쪽 발을 움직이는 경우
	if (right == next)
		ret = min(dfs(N + 1, left, right) + 1, ret);
	else if (next != left)
	{
		if (right == 0)
			ret = min(dfs(N + 1, left, next) + 2, ret);
		else
		{
			if (abs(right - next) == 1 || abs(right - next) == 3)
				ret = min(dfs(N + 1, left, next) + 3, ret);
			else
				ret = min(dfs(N + 1, left, next) + 4, ret);
		}
	}
	return ret;
}

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int temp;
	while (1) 
	{
		cin >> temp;
		if (temp == 0)
			break;
		arr[K] = temp;
		++K;
	}

	cout << dfs(0, 0, 0) << '\n';
	return 0;
}