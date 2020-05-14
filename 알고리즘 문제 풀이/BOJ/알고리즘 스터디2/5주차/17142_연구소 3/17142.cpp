#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int N, M;
int m[4][2] = { {0,-1},{0,1},{-1,0},{1,0} }; //�¿����
int room[51][51]; //ó�� ����
int visit[51][51]; //bfs������ �̿�
vector<pair<int, int>> virus; //virus���� ��ġ ����
bool c[11] = { 0 }; //virus�߿� m�� ����
int blankNum = 0; //ó�� ��ĭ�� �� ����

bool isRange(int y, int x) //����������� üũ
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

bool hasBlank() //��ĭ�� �ִ��� üũ
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (visit[i][j] == 0)
				return true;
	return false;
}

int bfs()
{
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < virus.size(); i++)
	{
		int y = virus[i].first;
		int x = virus[i].second;
		if (c[i])
		{
			q.push({ {y,x},0 });
			visit[y][x] = 1;
		}
	}

	int changedNum = 0;
	int ret = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		ret = max(ret, cnt);
		for (int i = 0; i < 4; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && visit[ny][nx] == 0)
			{
				visit[ny][nx] = 1;
				q.push({ {ny,nx},cnt + 1 });
				++changedNum; //��ĭ���� ���� �� üũ
				if (blankNum == changedNum)
				{
					ret += 1; //��� ��ĭ �� ������ �÷���
					break;
				}
			}
			else if (isRange(ny, nx) && visit[ny][nx] == 2) 
			//���þȵ� ���̷������� ��ġ�� ���ؼ��� 0�� ������ üũ�ϸ� �ȵ�
			{
				q.push({ {ny,nx},cnt + 1 });
				visit[ny][nx] = 1;
			}
		}
		if (blankNum == changedNum) //��ĭ ��� üũ�� ��� ����
			break;
	}

	if (hasBlank())
		ret = 1000000;
	return ret;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == 2) virus.push_back({ i,j });
			if (room[i][j] == 0) ++blankNum;
		}

	for (int i = 0; i < M; i++) c[i] = 1; //ó��m�� ����
	
	memcpy(visit, room, sizeof(visit));
	int ret = bfs();
	while (prev_permutation(c, c + virus.size())) //m�� ���� ����� ��
	{
		memcpy(visit, room, sizeof(visit));
		int temp = bfs();
		ret = min(ret, temp);
	}
	if (ret == 1000000) //��� ��츦 ���ص� �ȵǴ� ���
		cout << -1;
	else
		cout << ret;

	return 0;
}