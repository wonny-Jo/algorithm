#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T, n[1001]; cin >> T;
	int max_num = 0; //�Է� ���� n�߿� ���� ū��
	for (int i = 0; i < T; i++)
	{
		cin >> n[i];
		max_num = max(max_num, n[i]);
	}

	//�ڸ����� �ְ� �ڸ����� ���ڿ� ���Ͽ� �پ���� �ʴ� ���� ����� ��
	int dp[65][11] = { 0 }; //�ڸ� ��, �ְ��ڸ����� ���� 
	for (int j = 0; j < 10; j++)
		dp[1][j] = 1;

	//���� �ڸ����� �ڽź��� ���ų� ū ���ڵ��� �����ָ� ��
	//�ְ��ڸ����� ���ڰ� 10�� ��ġ���� �� �ڸ����� �հ��� �����// ��¿�
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
