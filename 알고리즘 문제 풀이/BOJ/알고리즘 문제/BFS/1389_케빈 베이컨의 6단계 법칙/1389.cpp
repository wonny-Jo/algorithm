#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

int N, M;
using namespace std;

void bfs(vector<int> Friend[101], int visit[101], int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		int size = Friend[x].size();
		for (int i = 0; i < size; ++i)
		{
			int y = Friend[x][i];
			if (!visit[y])
			{
				q.push(y);
				visit[y] = visit[x] + 1;
			}
		}
	}

}

int sumDist(int visit[101])
{
	int sum = 0;
	for (int i = 1; i <= N; ++i)
		sum += visit[i];
	return sum;
}

int searchMinValuePosition(vector<int> Friend[101])
{
	int min = INT32_MAX;
	int num;
	for (int i = 1; i <= N; ++i)
	{
		int visit[101] = { 0 };
		bfs(Friend, visit, i);
		int total = sumDist(visit);
		if (min > total)
		{
			min = total;
			num = i;
		}
	}
	return num;
}


int main()
{
	cin >> N >> M;
	vector<int> Friend[101];
	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		Friend[a].push_back(b);
		Friend[b].push_back(a);
	}

	cout << searchMinValuePosition(Friend);

	return 0;
}