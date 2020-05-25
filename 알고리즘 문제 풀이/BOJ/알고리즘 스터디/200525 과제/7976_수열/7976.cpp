#include<iostream>
#include<algorithm>
using namespace std;
int N, K;
int cnt[1000001][2], dp[1000001][2];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		++cnt[i % K + 1][a & 1];
	}
	dp[0][1] = 1e9;
	for (int i = 1; i <= K; ++i) {
		dp[i][0] = min(dp[i - 1][1] + cnt[i][0], dp[i - 1][0] + cnt[i][1]);
		dp[i][1] = min(dp[i - 1][0] + cnt[i][0], dp[i - 1][1] + cnt[i][1]);
	}
	cout << dp[K][0];

	return 0;
}