#include<iostream>
#include<vector>
using namespace std;
int d[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };//ºÏ¼­³²µ¿
int A, B, N, M;
int map[101][101] = { 0 };
vector<pair<pair<int, int>, int>> v;

bool isRange(int y, int x)
{
	if (y <= 0 || y > B || x <= 0 || x > A)
		return false;
	return true;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	cin >> A >> B >> N >> M;
	v.push_back({ {-1,-1},-1 });
	for (int i = 1; i <= N; i++)
	{
		int a, b; char c;
		cin >> a >> b >> c;
		int d;
		if (c == 'N') d = 0;
		else if (c == 'W') d = 1;
		else if (c == 'S') d = 2;
		else d = 3;

		map[b][a] = i;
		v.push_back({ {b,a},d });
	}
	for (int i = 0; i < M; i++)
	{
		int num, cnt; char command;
		cin >> num >> command >> cnt;
		if (command == 'F')
		{
			for (int j = 0; j < cnt; j++)
			{
				map[v[num].first.first][v[num].first.second] = 0;
				v[num].first.first += d[v[num].second][0];
				v[num].first.second += d[v[num].second][1];
				if (!isRange(v[num].first.first, v[num].first.second))
				{
					cout << "Robot " << num << " crashes into the wall";
					return 0;
				}
				if (map[v[num].first.first][v[num].first.second] != 0)
				{
					cout << "Robot " << num << " crashes into robot " << map[v[num].first.first][v[num].first.second];
					return 0;
				}
				map[v[num].first.first][v[num].first.second] = num;
			}
		}
		else if (command == 'L')
			v[num].second = (v[num].second + cnt) % 4;
		else if (command == 'R')
		{
			v[num].second = (v[num].second - cnt) % 4;
			if (v[num].second < 0)
				v[num].second += 4;
		}
	} 
	cout << "OK";
	return 0;
}