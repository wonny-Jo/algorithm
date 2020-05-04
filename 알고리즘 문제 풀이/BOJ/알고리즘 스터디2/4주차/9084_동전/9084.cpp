#include<iostream>
using namespace std;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	int arr[20];
	for (int a = 0; a < T; a++)
	{
		int N; cin >> N;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		int M; cin >> M;

		//���� ���� �������� ä��� �ִ� ��쿡 üũ
		//�� ���� �������� ���� ������� ������ �͵��� �����ָ�ȴ�.
		int dp[10001] = { 0 };
		dp[0] = 1;
		for (int i = 0; i < N; i++)
			for (int j = arr[i]; j <= M; j++)
				dp[j] += dp[j - arr[i]];
		cout << dp[M] << '\n';
	}

	return 0;
}
