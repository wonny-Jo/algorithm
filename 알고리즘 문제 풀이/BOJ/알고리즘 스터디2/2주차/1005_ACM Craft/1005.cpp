#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int arr[1001];
int T, N, K;
int connectNum[1001];
int dp[1001];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> T;
	for (int a = 0; a < T; a++)
	{
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];
			dp[i] = arr[i];
		}

		vector<int> v[1001];
		memset(connectNum, 0, sizeof(connectNum));
		for (int i = 0; i < K; i++)
		{
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			++connectNum[b];
		}

		int last; cin >> last;
		queue<int> q;
		for (int i = 1; i <= N; i++)
			if (connectNum[i] == 0)
				q.push(i);
		
		while (connectNum[last]!=0)
		{
			if (!q.empty())
			{
				int x = q.front();
				int size = v[x].size();
				for (int i = 0; i < size; i++)
				{
					--connectNum[v[x][i]];
					if (connectNum[v[x][i]] == 0)
						q.push(v[x][i]);

					dp[v[x][i]] = max(dp[v[x][i]], dp[x] + arr[v[x][i]]);
				}
				q.pop();
			}
		}

		cout << dp[last] << '\n';
	}

	return 0;
}