#include<iostream>
using namespace std;
int N;
int dy[4] = { 0,0,1,-1 }, dx[4] = { -1,1,0,0 }; //왼쪽 오른쪽 아래 위
bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

//영역을 구성하여 visited로 표현하는 함수
void checkRegion(int RGB[101][101], bool visited[101][101], int y, int x, int color)
{	
	if (!isRange(y, x))
		return;
	if (visited[y][x])
		return;
	if (color != RGB[y][x])
		return;

	visited[y][x] = true;
	for (int i = 0; i < 4; ++i)
		checkRegion(RGB, visited, y + dy[i], x + dx[i], color);
}

//영역을 찾으면 카운트하는 함수
int countRegion(int RGB[101][101], bool visited[101][101])
{
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j])
				continue;
			++cnt;
			checkRegion(RGB, visited, i, j, RGB[i][j]);
		}
	}
	return cnt;
}


int main()
{
	cin >> N;
	int RGB1[101][101] = { 0 }; //R:0, B:1, G:2
	int RGB2[101][101] = { 0 }; //R,G:0 B:1
	char color;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> color;
			if (color == 'B')
				RGB1[i][j] = RGB2[i][j] = 1;
			else if (color == 'G')
				RGB1[i][j] = 2;
		}
	}
	bool visited1[101][101] = { 0 };
	bool visited2[101][101] = { 0 };
	cout << countRegion(RGB1, visited1) <<' '<< countRegion(RGB2, visited2);

	return 0;
}