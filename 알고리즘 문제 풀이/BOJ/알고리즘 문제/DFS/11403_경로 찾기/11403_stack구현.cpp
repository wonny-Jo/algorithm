#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int N;

void dfs(vector<int> graph[101], bool visit[101], int start)
{
	stack<int> s;
	s.push(start);

	while (!s.empty())
	{
		int x=s.top();
		s.pop();

		int size = graph[x].size();
		for (int i = 0; i < size; ++i)
		{
			int y = graph[x][i];
			if (!visit[y])
			{
				visit[y] = true;
				s.push(x);
				s.push(y);
				break;
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