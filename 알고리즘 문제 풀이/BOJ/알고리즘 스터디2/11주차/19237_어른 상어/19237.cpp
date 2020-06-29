#include<iostream>
#include<string.h>
using namespace std;
int m[5][2] = { {0,0},{-1,0},{1,0},{0,-1},{0,1} };
int N, M, k;
pair<pair<int, int>,int> v[401]; //i,j,dir
int arr[21][21][2] = { 0 }, nextArr[21][21][2]; //number,cnt
int nextDir[401][5][4];
bool isDie[401] = { 0 };

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> k;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j][0];
			if (arr[i][j][0] != 0)
			{
				v[arr[i][j][0]] = { {i,j},0 };
				arr[i][j][1] = 1;
			}
		}
	for (int i = 1; i <= M; i++)
		cin >> v[i].second;
	
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> nextDir[i][j][k];

	memcpy(nextArr, arr, sizeof(arr));
	int ret = 1;
	bool isEnd;
	while (ret <= 1000)
	{
		++ret;
		for (int i = 1; i <= M; i++)
		{
			if (isDie[i])
				continue;
			//냄새가 없는곳이 있는지 먼저 체크
			int dir = v[i].second, next_dir;
			int j = 0;
			while (j < 4)
			{
				next_dir = nextDir[i][dir][j];
				int y = v[i].first.first + m[next_dir][0];
				int x = v[i].first.second + m[next_dir][1];
				if (isRange(y, x))
				{
					if (arr[y][x][0] == 0 || ret - arr[y][x][1] > k)
					{
						if (nextArr[y][x][1] == ret) //죽는 경우
						{
							isDie[i] = 1;
							break;
						}
						nextArr[y][x][0] = i;
						nextArr[y][x][1] = ret;
						v[i] = { { y,x },next_dir };
						break;
					}
				}
				++j;
			}
			if (j < 4)
				continue;

			// 냄새가 다 있으면 이전에 내 냄새가 있는곳체크
			j = 0;
			while (j < 4)
			{
				next_dir = nextDir[i][dir][j];
				int y = v[i].first.first + m[next_dir][0];
				int x = v[i].first.second + m[next_dir][1];
				if (isRange(y, x) && arr[y][x][0] == i)
				{
					nextArr[y][x][1] = ret;
					v[i] = { { y,x },next_dir };
					break;
				}
				++j;
			}
		}

		//1번만 살아있는지 체크
		isEnd = true;
		for (int i = 2; i <= M; i++)
		{
			if (!isDie[i])
			{
				isEnd = false;
				break;
			}
		}
		if (isEnd)
			break;
		memcpy(arr, nextArr, sizeof(arr));
	}
	if (!isEnd)
		cout << -1;
	else
		cout << ret - 1;

	return 0;
}