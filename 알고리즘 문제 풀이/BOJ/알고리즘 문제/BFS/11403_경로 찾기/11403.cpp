#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int N;

void bfs(vector<int> graph[101], bool visit[101], int start)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		int size = graph[x].size();
		for (int i = 0; i < size; ++i)
		{
			int y = graph[x][i];
			if (!visit[y])
			{
				q.push(y);
				visit[y] = true;
			}
		}
	}
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
		bfs(graph, visit, i);
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