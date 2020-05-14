#include<iostream>
#include<vector>
using namespace std;
int m[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int N, K, board[13][13];
vector<int> horse_num[13][13]; //각 위치의 말 번호로 순서 저장
vector<pair<int, pair<int, int>>> horse; //방향, 위치

bool isRange(int y, int x)
{
	if (y <= 0 || y > N || x <= 0 || x > N)
		return false;
	return true;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < K; i++)
	{
		int y, x, dir; cin >> y >> x >> dir;
		horse_num[y][x].push_back(i);
		horse.push_back({ dir,{y,x} });
	}

	int cnt = 1;
	while (cnt <= 1000)
	{
		int ny, nx;
		for (int i = 0; i < K; i++)
		{
			int y = horse[i].second.first;
			int x = horse[i].second.second;

			//현재 위치의 옮길 순서 찾기
			int start = 0;
			while (start < horse_num[y][x].size())
			{
				if (i == horse_num[y][x][start])
					break;
				++start;
			}
			
			ny = y + m[horse[i].first][0];
			nx = x + m[horse[i].first][1];
			//이동 위치가 벗어나거나 파란색
			if (!isRange(ny,nx)||board[ny][nx] == 2)
			{
				//반대쪽 체크
				if (horse[i].first % 2 == 1) ++horse[i].first;
				else --horse[i].first;

				ny = y + m[horse[i].first][0];
				nx = x + m[horse[i].first][1];
				//반대쪽도 파란색 혹은 범위외면 아무것도 안함
				if (!isRange(ny, nx) || board[ny][nx] == 2)
				{
				}
				//이동 위치가 흰색
				else if (board[ny][nx] == 0)
				{
					int size = horse_num[y][x].size();
					for (int j = start; j < size; j++)
					{
						int num = horse_num[y][x][j];
						horse[num].second.first = ny;
						horse[num].second.second = nx;
						horse_num[ny][nx].push_back(num);
					}
					if (horse_num[ny][nx].size() >= 4)
					{
						cout << cnt;
						return 0;
					}
					for (int j = start; j < size; j++)
						horse_num[y][x].pop_back();
				}
				//이동 위치가 빨간색
				else
				{
					int size = horse_num[y][x].size();
					for (int j = size - 1; j >= start; j--)
					{
						int num = horse_num[y][x][j];
						horse[num].second.first = ny;
						horse[num].second.second = nx;
						horse_num[ny][nx].push_back(num);
						horse_num[y][x].pop_back();
					}
					if (horse_num[ny][nx].size() >= 4)
					{
						cout << cnt;
						return 0;
					}
				}
			}
			//이동 위치가 흰색
			else if (board[ny][nx] == 0)
			{
				int size = horse_num[y][x].size();
				for (int j = start; j < size; j++)
				{
					int num = horse_num[y][x][j];
					horse[num].second.first = ny;
					horse[num].second.second = nx;
					horse_num[ny][nx].push_back(num);
				}
				if (horse_num[ny][nx].size() >= 4)
				{
					cout << cnt;
					return 0;
				}
				for (int j = start; j < size; j++)
					horse_num[y][x].pop_back();
			}
			//이동 위치가 빨간색
			else
			{
				int size = horse_num[y][x].size();
				for (int j = size-1; j >= start; j--)
				{
					int num = horse_num[y][x][j];
					horse[num].second.first = ny;
					horse[num].second.second = nx;
					horse_num[ny][nx].push_back(num);
					horse_num[y][x].pop_back();
				}
				if (horse_num[ny][nx].size() >= 4)
				{
					cout << cnt;
					return 0;
				}
			}
		}

		bool isEnd = false;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (horse_num[i][j].size() >= 4)
					isEnd = true;
		if (isEnd)
			break;
		++cnt;
	}
	cout << -1;


	return 0;
}