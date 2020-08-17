#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int d[10001];
int dp[10001][501] = { 0 };//n,m

//가능한 동작
//1. 현재 위치에서 달린다.
//2. 쉰다.
int run(int n, int m)
{
	if (n == N - m) //끝내는 위치는 이때부터 쉬어야함
		return 0;
	if (n > N - m) //더 큰 위치는 보면 안되는 부분들이므로 선택 안되게 반환
		return -10000000;

	int& ret = dp[n][m];
	if (ret != 0)
		return ret;

	if (m == 0) //첫 위치는 한번 더 가거나 한번 쉼
		ret = max(run(n + 1, m + 1) + d[n], run(n + 1, 0));
	else if (0 < m && m < M) //한번 더 가거나 m만큼 쉼
		ret = max(run(n + 1, m + 1) + d[n], run(n + m, 0));
	else if (m == M) //더 갈수 없으니 무조건 쉼
		ret = run(n + m, 0);

	return ret;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> d[i];

	cout<<run(0, 0);
	return 0;
}
