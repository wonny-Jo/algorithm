#include<iostream>
#include<queue>
using namespace std;
int S;
bool visit[3001][3001]; //출력된 숫자와 복사된 숫자

bool isRange(int x)
{
	if (x <= 0 || x > 3000)
		return false;
	return true;
}

int bfs(int start)
{
	visit[start][0] = 1;
	queue<pair<pair<int, int>,int>> q;
	q.push({ { start,0 },0 });

	while (!q.empty())
	{
		int x = q.front().first.first;
		int copyNum = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == S)
			return cnt;

		if (x != copyNum)
		{
			visit[x][x] = 1;
			q.push({ {x,x},cnt + 1 });
		}

		int temp = x + copyNum;
		if (isRange(temp) && !visit[temp][copyNum])
		{
			visit[x][copyNum] = 1;
			q.push({ {temp,copyNum},cnt + 1 });
		}
		temp = x - 1;
		if (isRange(temp) && !visit[temp][copyNum])
		{
			visit[x][copyNum] = 1;
			q.push({ {temp,copyNum},cnt + 1 });
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> S;
	cout << bfs(1);

	return 0;
}