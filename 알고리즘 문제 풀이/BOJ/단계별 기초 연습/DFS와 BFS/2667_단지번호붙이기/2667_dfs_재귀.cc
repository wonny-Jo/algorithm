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

void dfs(int result[26][26], int y, int x, int number)
{
	if (!isRange(y, x))
		return;
	if (!map[y][x])
		return;
	if (result[y][x])
		return;

	result[y][x] = number;
	for (int i = 0; i < 4; ++i)
		dfs(result, y + direcType[i][0], x + direcType[i][1], number);
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
				dfs(result, i, j, number);
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