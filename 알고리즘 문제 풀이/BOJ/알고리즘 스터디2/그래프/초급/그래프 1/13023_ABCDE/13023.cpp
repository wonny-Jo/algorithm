#include<iostream>
#include<vector>
using namespace std;
vector<int> v[2001];
int N, M;
bool isResult = 0;

void dfs(int start, int cnt,bool visit[2001])
{
	if (cnt == 5)
	{
		isResult = true;
		return;
	}

	visit[start] = 1;
	int size = v[start].size();
	for (int i = 0; i < size; i++)
	{
		int next = v[start][i];
		if (!visit[next])
			dfs(next, cnt + 1, visit);
	}
	visit[start] = 0;
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
		bool visit[2001] = { 0 };
		dfs(i, 1, visit);
		if(isResult)
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}