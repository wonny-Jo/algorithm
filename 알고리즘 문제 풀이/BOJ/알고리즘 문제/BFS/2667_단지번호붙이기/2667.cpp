#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int N;
bool map[26][26]; //지도 데이터
int direcType[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };//dy,dx 상하좌우 이동 경로

bool isRange(int y, int x)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;
	return true;
}

void bfs(int result[26][26], int y, int x, int number)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	result[y][x] = number;

	while (!q.empty())
	{
		int y_pos = q.front().first, x_pos = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int next_y = y_pos + direcType[i][0], next_x = x_pos + direcType[i][1];
			if (isRange(next_y, next_x) && map[next_y][next_x] && !result[next_y][next_x])
			{
				q.push({ next_y,next_x });
				result[next_y][next_x] = number;
			}
		}

	}
}

void countRegion(int result[26][26], int cnt[1000])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!result[i][j])
				continue;
			++cnt[result[i][j]];
		}
	}
}

void print(int cnt[350],int number)
{
	cout << number << endl;
	sort(cnt+1, cnt + number+1);
	for (int i = 1; i <= number; ++i)
		cout << cnt[i] << endl;
}

void searchRegion(int result[26][26])
{
	int number = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] && !result[i][j])
			{
				++number;
				bfs(result, i, j, number);
			}
		}
	}

	int cnt[1000] = { 0 };
	countRegion(result, cnt);
	if (number >= 1)
		print(cnt, number);
	else
		cout << 0;
}

int main()
{
	int result[26][26] = { 0 };
	cin >> N;
	char input;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> input;
			map[i][j]=(input=='1');
		}
	}

	searchRegion(result);

	return 0;
}