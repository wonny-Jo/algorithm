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

	for (int i = 1; i <= N; ++i) //입력된 물건의 개수
		for (int j = K; j >= 1; --j) //각 물건의 무게를 확인하여 업데이트
		//이때 K부터 도는 이유는 반대로 돌면 업데이트 된후에 다음것들이 영향을 받아서 한 물건을 두번 사용하는 경우가 발생.
			if (W[i] <= j)
				dp[j] = max(dp[j], dp[j - W[i]] + V[i]);

	cout << dp[K];
	return 0;
}