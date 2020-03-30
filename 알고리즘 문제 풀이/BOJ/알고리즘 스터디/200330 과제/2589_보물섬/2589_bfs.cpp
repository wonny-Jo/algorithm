#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int h, w;
bool c[51][51];
int Move[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

bool isRange(int y, int x)
{
	if (y < 0 || y >= h || x < 0 || x >= w)
		return false;
	return true;
}

int searchMax(int i, int j)
{
	queue < pair<pair<int, int>, int>> q;
	q.push({ {i,j},0 });
	c[i][j] = 1;

	int len = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (len < cnt)
			len = cnt;
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + Move[i][0];
			int nx = x + Move[i][1];
			if (isRange(ny, nx) && !c[ny][nx])
			{
				c[ny][nx] = 1;
				q.push({ {ny,nx},cnt + 1 });
			}
		}
	}
	return len;
}



int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	bool mask[51][51] = { 0 };
	string s[51];
	cin >> h >> w;
	for (int i = 0; i < h; ++i)
	{
		cin >> s[i];
		for (int j = 0; j < w; ++j)
			if (s[i][j] == 'W')
				mask[i][j] = 1;
	}

	int max = 0;
	for (int i = 0; i < h; ++i)
	{

		for (int j = 0; j < w; ++j)
		{
			if (!mask[i][j])
			{
				memcpy(c, mask, sizeof(mask));
				int temp = searchMax(i, j);
				if (max < temp)
					max = temp;
			}
		}
	}
	cout << max;


	return 0;
}