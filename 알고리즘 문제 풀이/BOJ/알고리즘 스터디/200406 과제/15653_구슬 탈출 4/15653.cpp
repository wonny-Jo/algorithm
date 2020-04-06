#include<iostream>
#include<queue>
using namespace std;
#define WALL '#'
#define GOAL 'O'

string s[10];
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int c[11][11][11][11] = { 0 };

//방향대로 좌표를 움직이는 함수
pair<pair<int, int>, pair<int, int>> moveDirection(pair<pair<int, int>, pair<int, int>> p, int Move[2])
{
	pair<int, int> red = p.first, blue = p.second;

	//빨간공부터 움직임
	red.first += Move[0]; red.second += Move[1];
	while (s[red.first][red.second] == '.' && red != blue)
	{
		red.first += Move[0];
		red.second += Move[1];
	}

	//빨간공이 파란공을 만나지 않았을경우
	//빨간공 위치가 벽인지 골인지 확인하면된다.
	if (red != blue)
	{
		//빨간공 최종 위치
		if (s[red.first][red.second] == WALL)
		{
			red.first -= Move[0];
			red.second -= Move[1];
		}
		//파란공 움직이기 시작
		blue.first += Move[0]; blue.second += Move[1];
		while (s[blue.first][blue.second] == '.' && red != blue)
		{
			blue.first += Move[0];
			blue.second += Move[1];
		}
		if (s[blue.first][blue.second] == WALL)
		{
			blue.first -= Move[0];
			blue.second -= Move[1];
		}
		if (red == blue && s[blue.first][blue.second] != GOAL)
		{
			blue.first -= Move[0];
			blue.second -= Move[1];
		}
	}
	//빨간공이 파란공 위치로 왔을경우
	else
	{
		//파란 공 먼저 움직임
		blue.first += Move[0]; blue.second += Move[1];
		while (s[blue.first][blue.second] == '.')
		{
			blue.first += Move[0];
			blue.second += Move[1];
		}
		if (s[blue.first][blue.second] == WALL)
		{
			blue.first -= Move[0];
			blue.second -= Move[1];
		}

		//빨간공 다시 움직이기 시작
		red.first += Move[0]; red.second += Move[1];
		while (s[red.first][red.second] == '.' && red != blue)
		{
			red.first += Move[0];
			red.second += Move[1];
		}
		if (s[red.first][red.second] == WALL)
		{
			red.first -= Move[0];
			red.second -= Move[1];
		}
		if (red == blue && s[red.first][red.second] != GOAL)
		{
			red.first -= Move[0];
			red.second -= Move[1];
		}
	}

	return { red,blue };
}

void bfs(pair<pair<int, int>, pair<int, int>> p)
{
	queue< pair<pair<int, int>, pair<int, int>>> q;
	q.push(p);
	c[p.first.first][p.first.second][p.second.first][p.second.second] = 0;

	while (!q.empty())
	{
		pair<int, int> red = q.front().first;
		pair<int, int> blue = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<pair<int, int>, pair<int, int>> movedPos = moveDirection({ red,blue }, direction[i]);
			//파란 공이 빠지는 경우는 제외

			if (s[movedPos.second.first][movedPos.second.second] != GOAL && c[red.first][red.second][blue.first][blue.second] + 1 < c[movedPos.first.first][movedPos.first.second][movedPos.second.first][movedPos.second.second])
			{
				q.push(movedPos);
				c[movedPos.first.first][movedPos.first.second][movedPos.second.first][movedPos.second.second] = c[red.first][red.second][blue.first][blue.second] + 1;
			}
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	int red[2], blue[2], goal[2];
	for (int i = 0; i < N; ++i)
	{
		cin >> s[i];
		for (int j = 0; j < M; ++j)
		{
			if (s[i][j] == 'R')
			{
				red[0] = i; red[1] = j;
				s[i][j] = '.';
			}
			else if (s[i][j] == 'B')
			{
				blue[0] = i; blue[1] = j;
				s[i][j] = '.';
			}
			else if (s[i][j] == 'O')
			{
				goal[0] = i; goal[1] = j;
			}
		}
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			for (int k = 0; k < N; ++k)
				for (int l = 0; l < M; ++l)
					c[i][j][k][l] = 100;

	pair<pair<int, int>, pair<int, int >> pos = { { red[0],red[1] },{blue[0],blue[1]} };

	bfs(pos);

	int ret = 100;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (i == goal[0] && j == goal[1])
				continue;
			if (c[goal[0]][goal[1]][i][j] < 100 && ret > c[goal[0]][goal[1]][i][j])
				ret = c[goal[0]][goal[1]][i][j];
		}
	}

	if (ret >= 100)
		cout << -1;
	else
		cout << ret;

	return 0;
}