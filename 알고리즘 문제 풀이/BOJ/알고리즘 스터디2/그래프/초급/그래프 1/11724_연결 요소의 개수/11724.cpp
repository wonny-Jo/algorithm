#include<iostream>
#include<vector>
using namespace std;
vector<int> a[1001];
bool c[1001] = { 0 };

void dfs(int node)
{
	c[node] = true;
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (c[next] == false)
			dfs(next);
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int components = 0;
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == false)
		{
			dfs(i);
			components += 1;
		}
	}
	cout << components;
	return 0;
}