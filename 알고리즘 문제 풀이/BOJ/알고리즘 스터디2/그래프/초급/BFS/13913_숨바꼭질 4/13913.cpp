#include<iostream>
#include<queue>
using namespace std;
int N, K;
int from[200001];
bool visit[200001] = { 0 };
int arr[200001];

bool isRange(int x)
{
	if (x < 0 || x>200000)
		return false;
	return true;
}

int bfs(int start)
{
	visit[start] = 1;
	queue<pair<int,int>> q;
	q.push({ start,0 });

	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == K)
			return cnt;

		int next = x - 1;
		if (isRange(next) && !visit[next])
		{
			from[next] = x;
			visit[next] = 1;
			q.push({ next,cnt+1 });
		}
		next = x + 1;
		if (isRange(next) && !visit[next])
		{
			from[next] = x;
			visit[next] = 1;
			q.push({ next,cnt+1 });
		}
		next = x * 2;
		if (isRange(next) && !visit[next])
		{
			from[next] = x;
			visit[next] = 1;
			q.push({ next,cnt+1 });
		}
	}
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> K;

	int ret = bfs(N);
	int prev = K;
	arr[0] = prev;
	for (int i = 1; i <= ret; i++)
	{
		prev = from[prev];
		arr[i] = prev;
	}
	cout << ret << '\n';
	for (int i = ret; i >= 0; i--)
		cout << arr[i] << ' ';

	return 0;
}