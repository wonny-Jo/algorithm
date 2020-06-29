#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int A[2001], B[2001];
int dp[2001][2001];
int N;

int dfs(int i,int j)
{
	if (i == N || j == N)
		return 0;
	int& ret = dp[i][j];
	if (ret != -1)
		return ret;

	if (A[i] > B[j])
		ret = max(ret, dfs(i, j + 1) + B[j]);
	ret = max(ret, dfs(i + 1, j));
	ret = max(ret, dfs(i + 1, j + 1));
	return ret;
}

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	int i = 0;
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0);
	return 0;
}
