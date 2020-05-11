#include<iostream>
#include <string.h>
#include<algorithm>
using namespace std;
int dp[102][102][102][2], gas[102][102][2];

int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	for (int a = 0; a < T; a++)
	{
		int n, m, l, g;
		cin >> n >> m >> l >> g;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j < m; j++)
				cin >> gas[i][j][0];
		for (int i = 1; i < n; i++)
			for (int j = 1; j <= m; j++)
				cin >> gas[i][j][1];

		memset(dp, 0x3f, sizeof(dp));
		dp[1][1][1][0] = dp[1][1][1][1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 1; k <= 100; k++) {
					int &d0 = dp[i][j][k][0], &d1 = dp[i][j][k][1];
					int g0 = gas[i][j - 1][0], g1 = gas[i - 1][j][1];
					int r0 = min(dp[i][j - 1][k][0], dp[i][j - 1][k - 1][1]);
					int r1 = min(dp[i - 1][j][k][1], dp[i - 1][j][k - 1][0]);
					d0 = min(d0, r0 + g0);
					d1 = min(d1, r1 + g1);
				}
			}
		}

		int ans = -1;
		for (int k = 100; k; k--) {
			if (dp[n][m][k][0] <= g) ans = k;
			if (dp[n][m][k][1] <= g) ans = k;
		}

		if (ans == -1) cout << ans;
		else cout << (n + m - 2) * l + ans - 1;
		cout << '\n';
	}

	return 0;
}