#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[2001];
int N, M;
bool isResult = 0;
bool visit[2001] = { 0 };

void dfs(int num, int cnt)
{
	if (cnt == 4)
	{
		isResult = true;
		return;
	}

	visit[num] = 1;
	int size = v[num].size();
	for (int i = 0; i < size; i++)
	{
		int next = v[num][i];
		if (!visit[next])
			dfs(next, cnt + 1);
	}
	visit[num] = 0;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		memset(visit, 0, sizeof(visit));
		dfs(i, 0);
		if (isResult)
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}