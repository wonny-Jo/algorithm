#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
double V;
int R, C;
double arr[101][101], time[101][101];

bool isRange(int y, int x)
{
	if (y < 0 || y >= R || x < 0 || x >= C)
		return false;
	return true;
}

void bfs()
{
	queue < pair<pair<int, int>, double>> q;
	q.push({ { 0,0 },1/V });
	time[0][0] = 0;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		double t = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && (time[ny][nx] == 0 || time[ny][nx] > time[y][x] + t))
			{
				time[ny][nx] = time[y][x] + t;
				q.push({ {ny,nx},t * pow(2,arr[ny][nx] - arr[y][x]) });
			}
		}
	}
}




int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> V >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];
	memset(time, 0, sizeof(time));
	bfs();
	--R; --C;
	cout.precision(2);
	cout << fixed <<time[R][C];
	return 0;
}
