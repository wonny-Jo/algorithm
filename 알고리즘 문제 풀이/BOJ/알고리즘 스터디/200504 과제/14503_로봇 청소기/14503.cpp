#include<iostream>
using namespace std;
int m[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }; //북동남서
int N, M;
int arr[51][51];


//청소 조건
// 1.현재 위치를 청소한다.
// 2.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
//   a.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
//   b.왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
//   c.네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
//   d.네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
int cleaning(int r, int c, int d)
{
	int y = r, x = c;

	int cnt = 0;
	while (1)
	{
		if (arr[y][x] == 1) //조건 d
			return cnt;
		if (arr[y][x] == 0)
		{
			arr[y][x] = 2;//조건 1
			++cnt;
		}
		bool isFind = false;
		for (int i = 1; i <= 4; i++)//조건 2
		{
			int ny = y + m[(d + i) % 4][0], nx = x + m[(d + i) % 4][1];//조건 b
			if (arr[ny][nx] == 0)//조건 a
			{
				d = (d + i) % 4;
				y = ny; x = nx;
				isFind = true;
				break;
			}
		}
		if (isFind)
			continue;

		//사방이 다 벽이거나 청소가 된 경우
		y = y - m[d][0];
		x = x - m[d][1];
		
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	int r, c, d; cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	//동서를 바꿔줌
	if (d == 1) 
		d = 3;
	else if (d == 3)
		d = 1;

	cout << cleaning(r, c, d);

	return 0;
}
