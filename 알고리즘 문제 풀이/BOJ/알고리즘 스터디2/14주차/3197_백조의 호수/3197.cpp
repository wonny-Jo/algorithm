#include<iostream> 
#include<vector> 
#include<queue> 
using namespace std;  
int m[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int R, C; 
string s[1501];
bool visit[1501][1501] = { 0 };
pair<int, int> start[2];
queue<pair<int, int>> water;

bool isRange(int y, int x)
{
	if (y < 0 || y >= R || x < 0 || x >= C)
		return false;
	return true;
}

int main() 
{
	cin.sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	cin >> R >> C; 
	int num = 0;
	for (int i = 0; i < R; i++) 
	{ 
		cin >> s[i]; 
		for (int j = 0; j < C; j++) 
		{ 
			if (s[i][j] == 'L')
			{
				start[num] = { i, j };
				++num;
			}
			if (s[i][j] == '.' || s[i][j] == 'L')
				water.push({ i, j });
		} 
	}

	queue<pair<int, int>> q; 
	q.push(start[0]);
	visit[start[0].first][start[0].second] = true;
	int ret = 0; 
	while (1) 
	{
		queue<pair<int, int>> nq; 
		bool isEnd = false; 
		while (!q.empty()) 
		{
			int y = q.front().first; 
			int x = q.front().second; 
			q.pop(); 
			if (y == start[1].first && x == start[1].second)
			{ 
				isEnd = true;
				break; 
			} 
			for (int i = 0; i < 4; i++) 
			{
				int ny = y + m[i][0]; 
				int nx = x + m[i][1]; 
				if (isRange(ny, nx) && !visit[ny][nx])
				{
					visit[ny][nx] = true;
					if (s[ny][nx] == 'X')
					{
						nq.push({ ny, nx });
						continue;
					}
					q.push({ ny, nx });
				}
			}
		} 
		if (isEnd) 
			break;
		q = nq;
		int size = water.size();
		while (size--)
		{ 
			int y = water.front().first;
			int x = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++) 
			{ 
				int ny = y + m[i][0]; 
				int nx = x + m[i][1]; 
				if (isRange(ny,nx)&& s[ny][nx] == 'X')
				{
					s[ny][nx] = '.';
					water.push({ ny, nx });
				} 
			} 
		} 
		ret++; 
	} 
	cout << ret << "\n"; 
	return 0; 
}