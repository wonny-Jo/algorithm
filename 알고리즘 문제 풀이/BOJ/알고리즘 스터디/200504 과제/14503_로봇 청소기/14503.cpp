#include<iostream>
using namespace std;
int m[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }; //�ϵ�����
int N, M;
int arr[51][51];


//û�� ����
// 1.���� ��ġ�� û���Ѵ�.
// 2.���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
//   a.���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
//   b.���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
//   c.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
//   d.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
int cleaning(int r, int c, int d)
{
	int y = r, x = c;

	int cnt = 0;
	while (1)
	{
		if (arr[y][x] == 1) //���� d
			return cnt;
		if (arr[y][x] == 0)
		{
			arr[y][x] = 2;//���� 1
			++cnt;
		}
		bool isFind = false;
		for (int i = 1; i <= 4; i++)//���� 2
		{
			int ny = y + m[(d + i) % 4][0], nx = x + m[(d + i) % 4][1];//���� b
			if (arr[ny][nx] == 0)//���� a
			{
				d = (d + i) % 4;
				y = ny; x = nx;
				isFind = true;
				break;
			}
		}
		if (isFind)
			continue;

		//����� �� ���̰ų� û�Ұ� �� ���
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
	//������ �ٲ���
	if (d == 1) 
		d = 3;
	else if (d == 3)
		d = 1;

	cout << cleaning(r, c, d);

	return 0;
}
