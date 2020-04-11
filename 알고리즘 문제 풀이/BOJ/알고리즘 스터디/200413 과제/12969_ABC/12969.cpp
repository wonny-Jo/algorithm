#include<iostream>
using namespace std;
int N, K;
char s[31];
bool dp[31][31][31][436][31] = { 0 }; //방문여부//이전에 이곳에서 정답이 나오지 않았다는 의미

bool findString(int numA, int numB, int numC, int sum, int n)
{
	if (numA + numB + numC == N)
	{
		if (sum == K)
			return true;
		return false;;
	}

	bool& ret = dp[numA][numB][numC][sum][n];
	if (ret)
		return false;
	ret = true;

	s[n] = 'A';
	if (findString(numA + 1, numB, numC, sum, n + 1))
		return true;

	s[n] = 'B';
	if (findString(numA, numB + 1, numC, sum + numA, n + 1))
		return true;

	s[n] = 'C';
	if (findString(numA, numB, numC + 1, sum + numA + numB, n + 1))
		return true;

	return false;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> K;
	
	if (findString(0, 0, 0, 0, 0))
	{
		for (int i = 0; i < N; i++)
			cout << s[i];
	}
	else
		cout << -1;
	return 0;
}