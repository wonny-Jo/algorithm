#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int m[12][2] = { {-2,-1},{-2,1}, {-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1},{-1,0},{1,0},{0,-1},{0,1} };
int K;
int W, H;
bool arr[201][201];
bool visit[201][201][31] = { 0 };
bool isRange(int y, int x)
{
	if (y < 0 || y >= H || x < 0 || x >= W)
		return false;
	return true;
}

int bfs()
{
	queue< pair<pair<int, int>, pair<int,int>>> q;
	visit[0][0][0] = 1;
	q.push({ { 0,0 }, {0,0} });

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int kCnt = q.front().second.first;
		int cnt = q.front().second.second;

		q.pop();
		if (y == H - 1 && x == W - 1)
			return cnt;

		if (kCnt < K)
		{
			for (int i = 0; i < 8; i++)
			{
				int ny = y + m[i][0];
				int nx = x + m[i][1];
				if (isRange(ny, nx) && visit[ny][nx][kCnt+1] == 0 && arr[ny][nx] == 0)
				{
					visit[ny][nx][kCnt + 1] = 1;
					q.push({ {ny,nx},{kCnt + 1,cnt + 1} });
				}
			}
		}
		for (int i = 8; i < 12; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && visit[ny][nx][kCnt] == 0 && arr[ny][nx] == 0)
			{
				visit[ny][nx][kCnt] = 1;
				q.push({ {ny,nx},{kCnt,cnt + 1} });
			}
		}
	}
	return -1;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> arr[i][j];
	cout << bfs();
	return 0;
}