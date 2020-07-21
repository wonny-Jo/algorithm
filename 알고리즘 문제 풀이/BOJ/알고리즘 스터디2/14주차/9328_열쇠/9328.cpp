#include<iostream>
#include<string.h>
#include<queue>
#include<deque>
using namespace std;
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int h, w;
string s[101];
bool visit[101][101], key[26];
bool isRange(int y, int x)
{
	if (y < 0 || y >= h || x < 0 || x >= w)
		return false;
	return true;
}

int bfs(int i, int j, deque<pair<int, int>> *temp)
{
	visit[i][j] = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });
	int cnt = 0;
	if ('a' <= s[i][j] && s[i][j] <= 'z')
	{
		key[s[i][j] - 'a'] = 1;
		if (!temp->empty())
		{
			int size = temp->size();
			for (int k = 0; k < size; k++)
			{
				if (key[s[temp->front().first][temp->front().second] - 'A'])
					q.push({ temp->front().first,temp->front().second });
				else
					temp->push_back(temp->front());
				temp->pop_front();
			}
		}
	}
	else if ('A' <= s[i][j] && s[i][j] <= 'Z')
	{
		if (!key[s[i][j] - 'A'])
		{
			temp->push_back({ i,j });
			return 0;
		}
	}
	else if (s[i][j] == '$')
		++cnt;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + m[i][0];
			int nx = x + m[i][1];
			if (isRange(ny, nx) && !visit[ny][nx] && s[ny][nx] != '*')
			{
				visit[ny][nx] = 1;
				if (s[ny][nx] == '$')
				{
					++cnt;
					q.push({ ny,nx });
				}
				else if ('a' <= s[ny][nx] && s[ny][nx] <= 'z')
				{
					key[s[ny][nx] - 'a'] = 1;
					q.push({ ny,nx });
					if (!temp->empty())
					{
						int size = temp->size();
						for (int i = 0; i < size; i++)
						{
							if (key[s[temp->front().first][temp->front().second] - 'A'])
								q.push({ temp->front().first,temp->front().second });
							else
								temp->push_back(temp->front());
							temp->pop_front();
						}
					}
				}
				else if ('A' <= s[ny][nx] && s[ny][nx] <= 'Z')
				{
					if (key[s[ny][nx] - 'A'])
						q.push({ ny,nx });
					else
						temp->push_back({ ny,nx });
				}
				else
					q.push({ ny,nx });
			}
		}
	}
	return cnt;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	for (int a = 0; a < t; a++)
	{
		cin >> h >> w;
		for (int i = 0; i < h; i++)
			cin >> s[i];
		string ss; cin >> ss;
		memset(key, 0, sizeof(key));
		memset(visit, 0, sizeof(visit));
		if (ss != "0")
			for (int i = 0; i < ss.size(); i++)
				key[ss[i] - 'a'] = 1;
		deque<pair<int, int>> temp;
		int ret = 0;
		for (int i = 0; i < h; i++)
		{
			if (s[i][0] != '*' && visit[i][0] == 0)
				ret += bfs(i, 0, &temp);
			if (s[i][w-1] != '*' && visit[i][w-1] == 0)
				ret += bfs(i, w-1, &temp);
		}
		for (int j = 0; j < w; j++)
		{
			if (s[0][j] != '*' && visit[0][j] == 0)
				ret += bfs(0, j, &temp);
			if (s[h-1][j] != '*' && visit[h-1][j] == 0)
				ret += bfs(h-1, j, &temp);
		}
		cout << ret << '\n';
	}

	return 0;
}