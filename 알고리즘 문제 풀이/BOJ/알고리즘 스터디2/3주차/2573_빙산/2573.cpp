#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int d[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
int arr[301][301], cnt = 0; //���� �迭�� ����
bool land[301][301] = { 0 }; //���̸� 1, �ƴϸ� 0
int N, M;
bool visit[301][301]; //bfs���� ���

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

void update()
{
	int minus[301][301] = { 0 }; //������ �𿩳����� ��.
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] != 0)
			{
				for (int k = 0; k < 4; k++)
				{
					int y = i + d[k][0], x = j + d[k][1];
					if (arr[y][x] == 0)
						--minus[i][j];
				}
			}

	//���� ������Ʈ
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (arr[i][j] != 0)
			{
				arr[i][j] = max(arr[i][j] + minus[i][j], 0);
				if (arr[i][j] == 0)
				{
					--cnt;
					land[i][j] = 0;
				}
			}
}


int bfs(int i, int j) //�ֺ��� ���鼭 ������ ������ ���� ���
{
	visit[i][j] = 0;
	queue<pair<int, int>> q;
	q.push({ i,j });
	int ret = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		++ret;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + d[i][0];
			int nx = x + d[i][1];
			if (isRange(ny, nx) && visit[ny][nx])
			{
				visit[ny][nx] = 0;
				q.push({ ny,nx });
			}
		}
	}
	return ret;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0)
			{
				++cnt;
				land[i][j] = 1;
			}
		}

	int ret = 0;
	while (cnt != 0)
	{
		memcpy(visit, land, sizeof(land));
		bool c = false;//bfs���Ҵ��� üũ
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visit[i][j])
				{
					c = true;
					if (cnt-bfs(i,j) != 0) //0�� �ƴϸ� ���� ������ �ִٴ°�
					{
						cout << ret;
						return 0;
					}
				}
			}
			if (c)
				break;
		}
		++ret;
		update(); //���� ������ ���� �� ��ġ, ���� ������Ʈ
	}
	cout << 0;

	return 0;
}