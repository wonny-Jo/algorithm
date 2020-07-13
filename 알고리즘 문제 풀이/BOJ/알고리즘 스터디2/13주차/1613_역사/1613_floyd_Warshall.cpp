#include <iostream>
using namespace std;
bool c[401][401] = { 0 };
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b; cin >> a >> b;
		c[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (c[i][k] && c[k][j])
					c[i][j] = 1;

	int s; cin >> s;
	for (int i = 0; i < s; i++)
	{
		int a, b; cin >> a >> b;
		if (c[a][b])
			cout << -1 << '\n';
		else if (c[b][a])
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}
