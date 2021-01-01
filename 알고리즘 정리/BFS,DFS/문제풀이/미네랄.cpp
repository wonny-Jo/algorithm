#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
int moveDir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int R, C;
int N;
string map[101];
bool visit[101][101];

bool isRange(int y, int x)
{
	if (y <= 0 || x < 0 || y > R || x >= C)
		return false;
	return true;
}

void bfs(int r, int c)
{
	memset(visit, 0, sizeof(visit));
	visit[r][c] = 1;
	map[r][c] = '.';
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	v.push_back({ r,c });
	q.push({ r,c });
	//클러스터 구하고
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + moveDir[i][0];
			int nx = x + moveDir[i][1];
			if (isRange(ny, nx) && visit[ny][nx] == 0 && map[ny][nx] == 'x')
			{
				visit[ny][nx] = 1;
				map[ny][nx] = '.';
				q.push({ ny,nx });
				v.push_back({ ny,nx });
			}
		}
	}

	//클러스터내 미네랄 하나씩 다운해보기
	int flag = 0;
	while (1)
	{
		vector<pair<int, int>> nv;
		for (int i = 0; i < v.size(); i++)
		{
			int y = v.at(i).first;
			int x = v.at(i).second;
			int ny = y + 1;
			nv.push_back({ ny,x });
			//바닥에 도착하거나 다른 크러스트 만남
			if (ny > R || map[ny][x] == 'x')
				flag = 1;
		}
		if (flag == 1)
		{
			for (int i = 0; i < v.size(); i++)
			{
				int y = v.at(i).first;
				int x = v.at(i).second;
				map[y][x] = 'x';
			}
			break;
		}
		else {
			v.clear();
			v = nv;
		}
	}

}
void solution(int sel, int num)
{
	memset(visit, 0, sizeof(visit));
	num = R - num + 1;
	if (sel % 2 == 0)
	{
		for (int i = 0; i < C; i++)
		{
			if (map[num][i] == 'x')
			{
				map[num][i] = '.';
				for (int j = 0; j < 4; j++)
				{
					int ny = num + moveDir[j][0];
					int nx = i + moveDir[j][1];
					if (isRange(ny, nx) && map[ny][nx] == 'x' && visit[ny][nx] == 0)
						bfs(ny, nx);
				}
				break;
			}
		}
	}
	else
	{
		for (int i = C - 1; i >= 0; i--)
		{
			if (map[num][i] == 'x')
			{
				map[num][i] = '.';
				for (int j = 0; j < 4; j++)
				{
					int ny = num + moveDir[j][0];
					int nx = i + moveDir[j][1];
					if (isRange(ny, nx) && map[ny][nx] == 'x' && visit[ny][nx] == 0)
						bfs(ny, nx);
				}
				break;
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		cin >> map[i];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		solution(i % 2, num);
	}

	for (int i = 1; i <= R; i++)
		cout << map[i] << '\n';
	return 0;
}