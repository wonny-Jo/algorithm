#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int N;

void dfs(vector<int> graph[101], bool visit[101], int start)
{
	if (visit[start])
		return;

	visit[start] = true;
	int size = graph[start].size();
	for (int i = 0; i < size; ++i)
		dfs(graph, visit, graph[start][i]);
}

void print(bool isConnected[101][101])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << isConnected[i][j] << ' ';
		cout << endl;
	}
}

void searchConnect(vector<int> graph[101])
{
	bool isConnected[101][101] = { 0 };
	for (int i = 0; i < N; ++i)
	{
		bool visit[101] = { 0 };
		dfs(graph, visit, i);
		for (int j = 0; j < N; ++j)
			isConnected[i][j] = visit[j];
	}
	print(isConnected);
}

int main()
{
	cin >> N;
	vector<int> graph[101];
	int input;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> input;
			if (input)
				graph[i].push_back(j);
		}
	}
	searchConnect(graph);

	return 0;
}