//1984kb, 28ms
#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<int> v;
bool visit[9] = { 0 };

void print()
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << '\n';
}

void dfs(int cnt)
{
	if (cnt == M)
	{
		print();
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			v.push_back(i);
			dfs(cnt + 1);
			v.pop_back();
			visit[i] = 0;
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	dfs(0);

	return 0;
}