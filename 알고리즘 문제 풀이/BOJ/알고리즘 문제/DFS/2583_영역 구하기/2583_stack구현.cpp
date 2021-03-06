#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
int M, N, K;
int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; //(dx,dy) 왼 오 위 아래

int min(int a, int b)
{
	return (a < b) ? a : b;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}

bool isRange(int y, int x)
{
	if (y < 0 || y >= M || x < 0 || x >= N)
		return false;
	return true;
}

//한 영역의 포함된 셀의 개수를 세는 함수
void dfs(int y, int x, int mask[101][101], int number)
{
	stack<pair<int, int>> s;
	s.push({ y,x });
	mask[y][x] = number;

	while (!s.empty())
	{
		int y_pos = s.top().first, x_pos = s.top().second;
		s.pop();
		for (int i = 0; i < 4; ++i)
		{
			int next_y = y_pos + direction[i][0], next_x = x_pos + direction[i][1];
			if (isRange(next_y, next_x) && !mask[next_y][next_x])
			{
				s.push({ y_pos,x_pos });
				s.push({ next_y,next_x });
				mask[next_y][next_x] = number;
				break;
			}
		}
	}
}

void countCell(int cnt[5000], int mask[101][101])
{
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mask[i][j]>0)
				++cnt[mask[i][j]];
		}
	}
}

void print(int cnt[5000], int number)
{
	cout << number << endl;
	sort(cnt + 1, cnt + number + 1);
	if (number > 0)
	{
		for (int i = 1; i <= number; ++i)
			cout << cnt[i] << ' ';
	}
}

//몇개의 영역으로 나뉘는지 찾는 함수
void searchRegion(int mask[101][101])
{
	int number = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!mask[i][j])
			{
				++number;
				dfs(i, j, mask, number);
			}
		}
	}
	int cnt[5000] = { 0 };
	countCell(cnt, mask);
	print(cnt, number);
}

int main()
{
	int mask[101][101] = { 0 };
	cin >> M >> N >> K;
	int leftBottom[2], rightTop[2];
	for (int i = 0; i < K; ++i)
	{
		cin >> leftBottom[0] >> leftBottom[1] >> rightTop[0] >> rightTop[1];
		int y_end = max(M - leftBottom[1], M - rightTop[1]),
			y_begin = min(M - leftBottom[1], M - rightTop[1]),
			x_end = max(leftBottom[0], rightTop[0]),
			x_begin = min(leftBottom[0], rightTop[0]);
		for (int j = y_begin; j < y_end; ++j)
		{
			for (int k = x_begin; k < x_end; ++k)
				mask[j][k] = -1;
		}
	}
	searchRegion(mask);

	return 0;
}