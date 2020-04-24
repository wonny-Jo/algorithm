#include<iostream>
#include<queue>

#define RECURDFS 1
#if !RECURDFS
#include<stack>
#endif

using namespace std;
bool arr[1001][1001] = { 0 };
bool visitBFS[1001] = { 0 };
bool visitDFS[1001] = { 0 };
int N, M, V;

void bfs(int start)
{
	visitBFS[start] = 1;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';

		for (int i = 1; i <= N; i++)
		{
			if (!visitBFS[i] && arr[x][i])
			{
				visitBFS[i] = 1;
				q.push(i);
			}
		}
	}
	cout << '\n';
}


#if !RECURDFS
void dfs(int start)
{
	visitDFS[start] = 1;
	stack<int> s;
	s.push(start);
	cout << start << ' ';
	while (!s.empty())
	{
		int x = s.top();
		s.pop();
		for (int i = 1; i <= N; ++i)
		{
			if (!visitDFS[i] && arr[x][i])
			{
				visitDFS[i] = 1;
				cout << i << ' ';
				s.push(x);
				s.push(i);
				break;
			}
		}
	}
	cout << '\n';
}
#else
void dfs(int start)
{
	visitDFS[start] = 1;
	cout << start << ' ';
	for (int i = 1; i <= N; ++i)
		if (!visitDFS[i] && arr[start][i])
			dfs(i);
}
#endif

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(V);	
#if RECURDFS
	cout << '\n';
#endif

	bfs(V);
	
	return 0;
}