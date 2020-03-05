#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
int M, N, K;
int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; //(dx,dy) �� �� �� �Ʒ�

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

//�� ������ ���Ե� ���� ������ ���� �Լ�
int dfs(int y, int x, int mask[101][101],int number)
{
	if (!isRange(y, x))
		return 0;
	if (mask[y][x])
		return 0;
	mask[y][x] = number;
	for (int i = 0; i < 4; ++i)
		dfs(y + direction[i][1], x + direction[i][0], mask, number);
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
	for (int i = 1; i <= number; ++i)
	{
		cout << cnt[i] << ' ';
	}
}

//��� �������� �������� ã�� �Լ�
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