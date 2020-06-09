#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int m[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
string s[12];
int ret = 0;

bool isRange(int y, int x)
{
	if (y < 0 || y >= 12 || x < 0 || x >= 6)
		return false;
	return true;
}

void bfs()
{
	while (1)
	{
		priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //4���� �Ǿ ��Ʈ���ֵ� ����
		bool visit[12][6] = { 0 };
		for (int i = 11; i >= 0; i--) //��ȸ�ϸ鼭 4���Ǵ� �ֵ� �� ��Ʈ��
		{
			for (int j = 0; j < 6; j++)
			{
				if (s[i][j] == '.')
					continue;
				else
				{
					//bfs ����
					queue<pair<int, int>> q, que;
					char col = s[i][j];
					q.push({ i,j });
					que.push({ i,j });
					visit[i][j] = 1;

					while (!q.empty())
					{
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						for (int i = 0; i < 4; i++)
						{
							int ny = y + m[i][0];
							int nx = x + m[i][1];
							if (isRange(ny, nx) && !visit[ny][nx] && s[ny][nx] == col)
							{
								visit[ny][nx] = 1;
								q.push({ ny, nx });
								que.push({ ny,nx });
							}
						}
					}

					if (que.size() >= 4) //������ ���
					{
						while (!que.empty())
						{
							pq.push({ que.front().first, que.front().second });
							que.pop();
						}
					}
				}
			}
		}

		if (pq.empty())
			break;
		//4���̻� ��ġ�Ȱ͵��� ����
		while (!pq.empty())
		{
			pair<int, int> x = pq.top();
			pq.pop();
			for (int i = x.first; i > 0; i--)
				s[i][x.second] = s[i - 1][x.second];
			s[0][x.second] = '.';
		}
		++ret;
	}
}

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 12; i++)
		cin >> s[i];

	bfs();
	cout << ret;
	return 0;
}