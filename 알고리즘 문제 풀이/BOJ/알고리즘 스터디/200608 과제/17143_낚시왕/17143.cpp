#include<iostream>
#include<vector>
using namespace std;
int m[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; //ºÏ³²µ¿¼­
pair<int, pair<int, int>> v[101][101];

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int R, C, M; cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
		v[r][c] = { z,{s,d - 1} };
	}

	int sum = 0;
	for (int i = 1; i <= C; i++)
	{
		for (int j = 1; j <= R; j++) 
			if (v[j][i].first!=0) 
			{ 
				sum += v[j][i].first; 
				v[j][i].first = 0;
				break; 
			}

		vector<pair<pair<int, int>, pair<int, pair<int, int>>>> temp;
		for (int a = 1; a <= R; a++)
		{
			for (int b = 1; b <= C; b++)
			{
				if (v[a][b].first != 0)
				{
					temp.push_back({ {a,b},v[a][b] });
					v[a][b].first = 0;
				}
			}
		}

		for (int a = 0; a<temp.size(); a++)
		{
			int r = temp[a].first.first;
			int c = temp[a].first.second;
			int z = temp[a].second.first;
			int s = temp[a].second.second.first;
			int d = temp[a].second.second.second;;
			
			if(d == 0 || d == 1) 
			{ 
				int next = r + (s % (2*R-2)) * m[d][0];
				for (int p = 0; p < 2; p++)
				{
					if (next > R)
					{
						next = 2 * R - next;
						d = 1 - d;
					}
					else if (next < 1)
					{
						next = 2 - next;
						d = 1 - d;
					}
				}
				r = next;
			} 
			else 
			{ 
				int next = c + (s % (2*C-2)) * m[d][1];
				for (int p = 0; p < 2; p++)
				{
					if (next > C)
					{
						next = 2 * C - next;
						d = 5 - d;
					}
					else if (next < 1)
					{
						next = 2 - next;
						d = 5 - d;
					}
				}
				c = next;
			} 

			if (v[r][c].first < z)
				v[r][c] = { z,{ s,d } };
		}
	}
	cout << sum;
	return 0;
}