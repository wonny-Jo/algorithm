#include<iostream>
#include<vector>
using namespace std;
int m[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int N, K, board[13][13];
vector<int> horse_num[13][13]; //�� ��ġ�� �� ��ȣ�� ���� ����
vector<pair<int, pair<int, int>>> horse; //����, ��ġ

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

			//���� ��ġ�� �ű� ���� ã��
			int start = 0;
			while (start < horse_num[y][x].size())
			{
				if (i == horse_num[y][x][start])
					break;
				++start;
			}
			
			ny = y + m[horse[i].first][0];
			nx = x + m[horse[i].first][1];
			//�̵� ��ġ�� ����ų� �Ķ���
			if (!isRange(ny,nx)||board[ny][nx] == 2)
			{
				//�ݴ��� üũ
				if (horse[i].first % 2 == 1) ++horse[i].first;
				else --horse[i].first;

				ny = y + m[horse[i].first][0];
				nx = x + m[horse[i].first][1];
				//�ݴ��ʵ� �Ķ��� Ȥ�� �����ܸ� �ƹ��͵� ����
				if (!isRange(ny, nx) || board[ny][nx] == 2)
				{
				}
				//�̵� ��ġ�� ���
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
				//�̵� ��ġ�� ������
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
			//�̵� ��ġ�� ���
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
			//�̵� ��ġ�� ������
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