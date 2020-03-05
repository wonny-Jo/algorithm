#include<iostream>
using namespace std;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int M, N;
int board[1001][1001];
int resultBoard[1001][1001];

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

int check_end()
{
	bool isChanged = false;
	bool isEnd = true; //보드에 0이 하나도 없는지 체크
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] != resultBoard[i][j])
			{
				isChanged = true;
				board[i][j] = resultBoard[i][j];
			}
			if (board[i][j] == 0)
				isEnd = false;
		}
	}
	if (!isChanged)
		return -1; //업데이트가 되지 않는 상황이면 -1
	if (isEnd)
		return 0; //모든 보드가 대 채워졌으면 0
	return 1; //아직 더 채워야하면 1

}

void expand()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == 1)
			{
				for (int direct = 0; direct < 4; ++direct)
				{
					int y = i + dy[direct], x = j + dx[direct];
					if (isRange(y, x) && resultBoard[y][x] == 0)
						resultBoard[y][x] = 1;
				}
			}
		}
	}
}


int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> resultBoard[i][j];

	int result = check_end();
	if (!result)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			board[i][j] = resultBoard[i][j];

	int count = 1;
	while (1)
	{
		expand();
		result = check_end();
		if (result == -1)
		{
			cout << -1;
			break;
		}
		else if (result == 0)
		{
			cout << count;
			break;
		}
		
		++count;
	}
		

	return 0;
}