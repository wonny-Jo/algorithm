#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T, n[1001]; cin >> T;
	int max_num = 0; //입력 받은 n중에 가장 큰것
	for (int i = 0; i < T; i++)
	{
		cin >> n[i];
		max_num = max(max_num, n[i]);
	}

	//자릿수와 최고 자릿수의 숫자에 대하여 줄어들지 않는 수의 경우의 수
	int dp[65][11] = { 0 }; //자릿 수, 최고자릿수의 숫자 
	for (int j = 0; j < 10; j++)
		dp[1][j] = 1;

	//이전 자릿수의 자신보다 같거나 큰 숫자들은 더해주면 됨
	//최고자릿수의 숫자가 10인 위치에는 그 자릿수의 합값이 저장됨// 출력용
	for (int i = 2; i <= max_num; i++)
	{
		for (int j = 9; j >= 0; j--)
		{
			dp[i - 1][10] += dp[i - 1][j];
			dp[i][j] = dp[i - 1][10];;
		}
	}
	for (int j = 0; j < 10; j++)
		dp[max_num][10] += dp[max_num][j];


	for (int i = 0; i < T; i++)
		cout << dp[n[i]][10] << '\n';
	return 0;
}
