#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int n; cin >> n;
	int first, second; cin >> first >> second;
	int m; cin >> m;

	vector<int> v[101];
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	int cnt[101];
	memset(cnt, -1, sizeof(cnt));

	// bfs
	queue<int> q;
	q.push(first);
	++cnt[first];

	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		int size = v[a].size();
		for (int i = 0; i < size; ++i)
		{
			int b = v[a][i];
			if (cnt[b] == -1)
			{
				cnt[b] = cnt[a] + 1;
				q.push(b);
			}
		}
	}

	cout << cnt[second];
	return 0;
} 