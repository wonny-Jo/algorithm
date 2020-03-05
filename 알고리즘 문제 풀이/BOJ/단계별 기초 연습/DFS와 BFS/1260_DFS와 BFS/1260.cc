#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void BFS(vector<int> data[1001], bool BFS_check[1001], int start)
{
	queue<int> q;
	q.push(start);
	BFS_check[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		int size = data[x].size();
		for (int i = 0; i <size; ++i)
		{
			int y = data[x][i];
			if (!BFS_check[y]) {
				q.push(y);
				BFS_check[y] = true;
			}
		}
	}
	cout << endl;
}

void DFS(vector<int> data[1001], bool DFS_check[1001], int start)
{
	stack<int> s;
	s.push(start);
	DFS_check[start] = true;
	cout << start << ' ';
	while (!s.empty())
	{
		int x = s.top();
		s.pop();
		int size = data[x].size();
		for (int i = 0; i < size; ++i)
		{
			int y = data[x][i];
			if (!DFS_check[y])
			{
				cout << y << ' ';
				DFS_check[y] = true;
				s.push(x);
				s.push(y);
				break;
			}
		}
	}
	cout << endl;
}


int main()
{
	vector<int> data[1001];
	int N, M, V;
	cin >> N >> M >> V;
	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		data[a].push_back(b);
		data[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i)
		sort(data[i].begin(), data[i].end());
	bool DFS_check[1001] = { 0 };
	bool BFS_check[1001] = { 0 };

	DFS(data, DFS_check, V);
	BFS(data, BFS_check, V);


	return 0;
}