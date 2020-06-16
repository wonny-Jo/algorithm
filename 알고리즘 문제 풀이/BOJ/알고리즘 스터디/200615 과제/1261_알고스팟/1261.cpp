#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int Move[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
string s[101];
queue<pair<int, int>> wall; //부딪히는 벽 저장.
bool visit[101][101] = { 0 };
int N, M;

bool isRange(int y, int x)
{
	if (y < 0 || y >= M || x < 0 || x >= N)
		return false;
	return true;
}

void bfs(int i, int j)
{
	if (visit[i][j])
		return;

	visit[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + Move[i][0];
			int nx = x + Move[i][1];
			if (isRange(ny, nx) && !visit[ny][nx])
			{
				if (s[ny][nx] == '1')
				{
					wall.push({ ny,nx });
				}
				else
				{
					visit[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> s[i];

	int cnt = 0;
	bfs(0, 0);
	while (!visit[M - 1][N - 1])
	{
		vector<pair<int, int>> v;
		while (!wall.empty())
		{
			int y = wall.front().first;
			int x = wall.front().second;
			wall.pop();
			if (s[y][x] == '1')
			{
				v.push_back({ y,x });
				s[y][x] = '0';
			}
		}
		for (int i = 0; i < v.size(); ++i)
		{
			int y = v[i].first;
			int x = v[i].second;
			bfs(y, x);
		}
		++cnt;
	}
	cout << cnt;

	return 0;
}