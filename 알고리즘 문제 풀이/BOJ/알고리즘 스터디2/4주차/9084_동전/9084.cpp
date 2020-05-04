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

		//제일 작은 동전부터 채울수 있는 경우에 체크
		//그 다음 동전들은 이전 동전들로 세어진 것들을 더해주면된다.
		int dp[10001] = { 0 };
		dp[0] = 1;
		for (int i = 0; i < N; i++)
			for (int j = arr[i]; j <= M; j++)
				dp[j] += dp[j - arr[i]];
		cout << dp[M] << '\n';
	}

	return 0;
}
