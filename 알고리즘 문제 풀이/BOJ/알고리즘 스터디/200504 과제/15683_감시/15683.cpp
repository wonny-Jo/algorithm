#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int m[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
vector<pair<int, int>> v; //cctv위치
int room[9][9], temp[9][9];
int N, M;

int countZero()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 0)
				++cnt;
	return cnt;
}

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

void detect(int i,int j, int direction) //방향에 따른 cctv감시
{
	int y = i + m[direction][0];
	int x = j + m[direction][1];
	while (isRange(y, x)&&room[y][x]!=6)
	{
		if (temp[y][x] == 0)
			temp[y][x] = -1;
		y += m[direction][0];
		x += m[direction][1];
	}
}

void detectRoom(int num)
{
	int sel;
	for (int i = 0; i < v.size(); i++)
	{
		sel = num % 4; //방향 결정
		num /= 4;
		int y = v[i].first, x = v[i].second;
		
		//cctv종류에따라 탐색방법나눔
		if (room[y][x] == 1)
		{
			detect(y, x, sel);
		}
		else if (room[y][x] == 2)
		{
			detect(y, x, sel);
			detect(y, x, (sel + 2) % 4);
		}
		else if (room[y][x] == 3)
		{
			detect(y, x, sel);
			detect(y, x, (sel + 1) % 4);
		}
		else if (room[y][x] == 4)
		{
			detect(y, x, sel);
			detect(y, x, (sel + 1) % 4);
			detect(y, x, (sel + 2) % 4);
		}
		else if (room[y][x] == 5)
		{
			detect(y, x, sel);
			detect(y, x, (sel + 1) % 4);
			detect(y, x, (sel + 2) % 4);
			detect(y, x, (sel + 3) % 4);
		}
	}
}

int solve()
{
	int ret = 100;
	int size = 1 << 2 * v.size(); //완전탐색
	for (int i = 0; i < size; i++)
	{
		memcpy(temp, room, sizeof(temp)); //초기화
		detectRoom(i);
		ret=min(ret,countZero());
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
			cin >> room[i][j];
			if (room[i][j] != 0 && room[i][j] != 6) //cctv위치 저장
				v.push_back({ i,j });
		}

	cout << solve();

	return 0;
}
