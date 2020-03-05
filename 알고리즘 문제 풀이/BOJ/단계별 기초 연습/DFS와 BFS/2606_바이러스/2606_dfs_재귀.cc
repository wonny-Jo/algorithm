#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int countVisit(bool visit[101])
{
	int cnt = 0;
	for (int i = 2; i < 101; ++i)
	{	
		if (visit[i])
			++cnt;
	}
	return cnt;
}

void dfs(vector<int> data[101],bool visit[101],int start)
{
	visit[start] = true;
	int size = data[start].size();
	for (int i = 0; i < size; ++i)
	{
		int y = data[start][i];
		if (!visit[y])
		{
			visit[y] = true;
			dfs(data, visit, y);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> data[101];
	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		data[a].push_back(b);
		data[b].push_back(a);
	}
	bool visit[101] = { 0 };
	dfs(data, visit,1);
	cout << countVisit(visit);
	return 0;
}