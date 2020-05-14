#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
int N, M;
int m[4][2] = { {0,-1},{0,1},{-1,0},{1,0} }; //좌우상하
int room[51][51]; //처음 상태
int visit[51][51]; //bfs돌릴때 이용
vector<pair<int, int>> virus; //virus들의 위치 저장
bool c[11] = { 0 }; //virus중에 m개 선택
int blankNum = 0; //처음 빈칸의 수 저장

bool isRange(int y, int x) //범위벗어나는지 체크
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

bool hasBlank() //빈칸이 있는지 체크
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
				++changedNum; //빈칸에서 변한 수 체크
				if (blankNum == changedNum)
				{
					ret += 1; //방금 한칸 더 갔으니 올려줌
					break;
				}
			}
			else if (isRange(ny, nx) && visit[ny][nx] == 2) 
			//선택안된 바이러스들의 위치에 대해서는 0의 개수를 체크하면 안됨
			{
				q.push({ {ny,nx},cnt + 1 });
				visit[ny][nx] = 1;
			}
		}
		if (blankNum == changedNum) //빈칸 모두 체크한 경우 끝냄
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

	for (int i = 0; i < M; i++) c[i] = 1; //처음m개 선택
	
	memcpy(visit, room, sizeof(visit));
	int ret = bfs();
	while (prev_permutation(c, c + virus.size())) //m개 선택 경우의 수
	{
		memcpy(visit, room, sizeof(visit));
		int temp = bfs();
		ret = min(ret, temp);
	}
	if (ret == 1000000) //모든 경우를 다해도 안되는 경우
		cout << -1;
	else
		cout << ret;

	return 0;
}