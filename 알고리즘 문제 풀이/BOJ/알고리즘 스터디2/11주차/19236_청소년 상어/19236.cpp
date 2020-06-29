#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int m[8][2] = { {-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1} };
pair<pair<int, int>, pair<int, bool>> v[17]; //i,j,dir,isDie
int arr[5][5];
int ret = 0;

bool isRange(int y, int x)
{
	if (y < 0 || y >= 4 || x < 0 || x >= 4)
		return false;
	return true;
}

void Move(int a,int b)
{
	for (int i = 1; i <= 16; i++)
	{
		if (v[i].second.second == false)
		{
			int dir = v[i].second.first;
			int dir_temp = dir;
			
			int cnt = 0;
			while (cnt<8)
			{
				int y = v[i].first.first + m[dir][0];
				int x = v[i].first.second + m[dir][1];
				if (isRange(y,x)&&!(y==a&&x==b))
				{
					if (arr[y][x] == 0)
					{
						arr[v[i].first.first][v[i].first.second] = 0;
						v[i].first.first = y;
						v[i].first.second = x;
						arr[y][x] = i;
						v[i].second.first = dir;
					}
					else
					{
						int ny = v[i].first.first,nx = v[i].first.second;
						pair<pair<int, int>, pair<int, bool>> temp = v[i];
						v[i].first = v[arr[y][x]].first;
						v[i].second.first = dir;
						v[arr[y][x]].first = temp.first;
						swap(arr[ny][nx], arr[y][x]);
					}
					break;
				}
				++cnt;
				++dir;
				dir %= 8;
			}
		}
	}
}

void dfs(int i, int j, int dir, int sum)
{
	ret = max(ret, sum);
	int temp[5][5];
	pair<pair<int, int>, pair<int, bool>> v2[17];
	memcpy(temp, arr, sizeof(temp));
	memcpy(v2, v, sizeof(v2));

	Move(i,j);//물고기 자리바꿈
	int ret = 0;
	int y = i, x = j;
	for (int a = 0; a < 3; a++)
	{
		y += m[dir][0]; x += m[dir][1];
		if (isRange(y, x)&&arr[y][x])
		{
			//잡아먹음
			int num = arr[y][x];
			arr[y][x] = 0;
			v[num].second.second = true;
			dfs(v[num].first.first, v[num].first.second, v[num].second.first, sum + num);

			arr[y][x] = num;
			v[num].second.second = false;
		}
	}

	memcpy(arr, temp, sizeof(temp));
	memcpy(v, v2, sizeof(v2));
	
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b; cin >> a >> b;
			v[a] = { {i,j},{b % 8,false} };
			arr[i][j] = a;
		}
	}
	int num = arr[0][0];
	arr[0][0] = 0;
	v[num].second.second = true;
	dfs(0, 0, v[num].second.first, num);
	cout << ret;
	return 0;
}