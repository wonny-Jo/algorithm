#include<iostream>
#include<algorithm>
using namespace std;
int N, K;
int W[101], V[101];
int dp[100001] = { 0 };

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		cin >> W[i] >> V[i];

	for (int i = 1; i <= N; ++i) //�Էµ� ������ ����
		for (int j = K; j >= 1; --j) //�� ������ ���Ը� Ȯ���Ͽ� ������Ʈ
		//�̶� K���� ���� ������ �ݴ�� ���� ������Ʈ ���Ŀ� �����͵��� ������ �޾Ƽ� �� ������ �ι� ����ϴ� ��찡 �߻�.
			if (W[i] <= j)
				dp[j] = max(dp[j], dp[j - W[i]] + V[i]);

	cout << dp[K];
	return 0;
}