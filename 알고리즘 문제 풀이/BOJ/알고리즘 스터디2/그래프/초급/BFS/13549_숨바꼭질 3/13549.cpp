#include<iostream>
#include<queue>
using namespace std;
bool visit[200001] = { 0 };

bool isRange(int x)
{
	if (x < 0 || x>200000)
		return false;
	return true;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N, K;	
	cin >> N >> K;

	queue<pair<int, int>> q;
	visit[N] = 1;
	q.push({ N,0 });


	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == K)
		{
			cout << cnt;
			return 0;
		}

		int temp = x * 2;
		while (isRange(temp)&&!visit[temp])
		{
			visit[temp] = 1;
			q.push({ temp,cnt });
			temp *= 2;
		}
		temp = x - 1;
		if (isRange(temp)&&!visit[temp])
		{
			visit[temp] = 1;
			q.push({ temp,cnt + 1 });
		}
		temp = x + 1;
		if (isRange(temp) && !visit[temp])
		{
			visit[temp] = 1;
			q.push({ temp,cnt + 1 });
		}
	}

	return 0;
}