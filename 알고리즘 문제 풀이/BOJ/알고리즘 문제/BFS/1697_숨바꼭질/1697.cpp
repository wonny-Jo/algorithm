#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int N, K;

bool isRange(int x)
{
	if (x < 0 || x>200000)
		return false;
	return true;
}


int main()
{
	cin >> N >> K;
	bool c[200001];
	memset(c, 0, sizeof(c));
	queue<pair<int,int>> q;
	q.push({ N,0 });
	c[N] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int count = q.front().second;
		if (x == K)
		{
			cout << count;
			break;
		}
		q.pop();

		int nx = x + 1;
		if (isRange(nx) && c[nx] == 0)
		{
			c[nx] = 1; q.push({ nx,count + 1 });
		}
		nx = x - 1;
		if (isRange(nx) && c[nx] == 0)
		{
			c[nx] = 1; q.push({ nx,count + 1 });
		}
		nx = x * 2;
		if (isRange(nx) && c[nx] == 0)
		{
			c[nx] = 1; q.push({ nx,count + 1 });
		}
	}

	return 0;
}