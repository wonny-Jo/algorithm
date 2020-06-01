#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int parent[200001];
int m, n;

int getParent(int parent[], int x)
{
	if (parent[x] == x) 
		return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) 
		parent[b] = a;
	else 
		parent[a] = b;
}

bool findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 1;
	return 0;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	while (1)
	{
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		vector<pair<int, pair<int, int>>> v;
		for (int i = 0; i < n; i++)
		{
			int x, y, z; cin >> x >> y >> z;
			v.push_back({ z,{x,y} });
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++)
			parent[i] = i;

		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (!findParent(parent, v[i].second.first, v[i].second.second))
				unionParent(parent, v[i].second.first, v[i].second.second);
			else
				sum += v[i].first;
		}
		cout << sum << '\n';
	}

	return 0;
}