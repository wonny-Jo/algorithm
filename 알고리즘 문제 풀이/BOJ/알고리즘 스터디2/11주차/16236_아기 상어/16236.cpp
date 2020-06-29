#include<iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int m[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
int N;
int ret = 0, eating_num = 0;
int arr[21][21], start[2];
bool visit[21][21] = { 0 };

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

void bfs(int i, int j, int num)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ {i,j},0 });
	visit[i][j] = 1;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;

		if (arr[y][x]&&arr[y][x] < num)
		{
			vector<pair<int,int>> v;
			while (!q.empty()&&cnt == q.front().second)
			{
				int ny = q.front().first.first;
				int nx = q.front().first.second;
				if(arr[ny][nx] && arr[ny][nx] < num)
					v.push_back({ ny,nx });
				q.pop();
			}

			sort(v.begin(), v.end());
			arr[v[0].first][v[0].second] = 0;
			++eating_num;
			if (eating_num == num)
			{
				++num;
				eating_num = 0;
			}
			ret += cnt;
			memset(visit, 0, sizeof(visit));
			bfs(v[0].first, v[0].second, num);
			return;
		}
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && !visit[ny][nx] && arr[ny][nx] <= num)
			{
				q.push({ {ny,nx},cnt + 1 });
				visit[ny][nx] = 1;
			}
		}
	}
	return;
}


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				arr[i][j] = 0;
				start[0] = i; start[1] = j;
			}
		}
	}

	bfs(start[0], start[1], 2);
	cout << ret;

	return 0;
}