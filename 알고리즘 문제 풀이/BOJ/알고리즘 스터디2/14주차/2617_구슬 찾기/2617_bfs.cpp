#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
vector<int> v1[100], v2[100];
bool visit[100][100][2] = { 0 };
int cnt[100][2] = { 0 };

int bfs(int num)
{
	queue<int> q;
	visit[num][num][0] = 1;
	q.push(num);
	int cnt = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		int size = v1[x].size();
		for (int i = 0; i < size; i++)
		{
			int y = v1[x][i];
			if (!visit[num][y][0])
			{
				++cnt;
				visit[num][y][0] = 1;
				q.push(y);
			}
		}
	}

	if (cnt >= (N + 1) / 2)
		return 1;

	visit[num][num][1] = 1;
	q.push(num);
	cnt = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		int size = v2[x].size();
		for (int i = 0; i < size; i++)
		{
			int y = v2[x][i];
			if (!visit[num][y][1])
			{
				++cnt;
				visit[num][y][1] = 1;
				q.push(y);
			}
		}
	}
	if (cnt >= (N + 1) / 2)
		return 1;
	return 0;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	int ret = 0;
	for (int i = 1; i <= N; i++)
		ret += bfs(i);
	cout << ret;

	return 0;
}