#include<iostream>
#include<string.h>
using namespace std;
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int R, C, T;
int room[51][51];
int plusNum[51][51];
int start;

bool isRange(int y, int x)
{
	if (x <= 0 || x > C || y <= 0 || y > R)
		return false;
	return true;
}

void update() //먼지 퍼뜨리기
{
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			if (room[i][j] < 5)
				continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int y = i + m[k][0], x = j + m[k][1];
				if (isRange(y, x) && room[y][x] != -1)
				{
					++cnt;
					plusNum[y][x] += room[i][j] / 5;
				}
			}
			plusNum[i][j] -= cnt * (room[i][j] / 5);
		}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			room[i][j] += plusNum[i][j];
}

void cleaning() //공기청정기 돌림
{
	for (int i = start-2; i >= 2; i--)
		room[i][1] = room[i - 1][1];
	for (int i = start+1; i < R; i++)
		room[i][1] = room[i + 1][1];
	
	for (int i = 1; i < C; i++)
	{
		room[1][i] = room[1][i + 1];
		room[R][i] = room[R][i + 1];
	}

	for (int i = 1; i < start-1; i++)
		room[i][C] = room[i + 1][C];
	for (int i = R; i > start; i--)
		room[i][C] = room[i - 1][C];
	
	for (int i = C; i > 2; i--)
	{
		room[start - 1][i] = room[start - 1][i - 1];
		room[start][i] = room[start][i - 1];
	}
	room[start - 1][2] = 0;
	room[start][2] = 0;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == -1)
				start = i;
		}
	for (int i = 0; i < T; i++)
	{
		memset(plusNum, 0, sizeof(plusNum));
		update();
		cleaning();
	}

	int ret = 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			ret += room[i][j];
	cout << ret + 2; //공기청정기 2개 더해줌
	return 0;
}
