#include<iostream>
using namespace std;
int m[4][2] = { {0,1},{-1,0},{0,-1},{1,0} }; //오위왼아

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	bool visit[101][101] = { 0 };
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, d, g; cin >> x >> y >> d >> g;
		
		//0세대 ㄱㄱ
		int stack_dir[2000];
		visit[y][x] = 1;
		y+= m[d][0]; x += m[d][1];
		visit[y][x] = 1;
		stack_dir[0] = d;
		int dir_num = 0, cnt = 0;//이전 방향 갯수, 세대 업데이트

		//1세대~
		while (cnt != g)
		{
			int temp = dir_num;
			for (int j = dir_num; j >=0; j--)
			{
				stack_dir[temp + 1] = (stack_dir[j] + 1) % 4;
				y += m[stack_dir[temp+1]][0]; x += m[stack_dir[temp+1]][1];
				visit[y][x] = 1;
				++temp;
			}
			dir_num = temp;
			++cnt;
		}
	}
	
	int ret = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (visit[i][j] && visit[i][j + 1] && visit[i + 1][j] && visit[i + 1][j + 1])
				++ret;
	
	cout << ret;

	return 0;
}