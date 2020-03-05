#include<iostream>
#include<vector>
using namespace std;

int H, W;

// ����� ���������� ������� �����Ѵٸ� ���� ����� ���� 4���� ���̴�.
int coverType[4][3][2]{
	{{0, 0}, {1, 0}, {0, 1}},/////////��
	{{0, 0}, {1, 0}, {1, 1}},///////// �� 
	{{0, 0}, {1, 1}, {0, 1}},/////////��
	{{0, 0}, {-1, 1}, {0, 1}} ///////// ��
};

//coverType���� ����� �������ִ��� ���θ� ��Ÿ���� �Լ�
bool set(int board[21][21], int y, int x, int type, int delta)
{
	bool isSet = true;
	for (int i = 0; i < 3; ++i) {
		int ny = y + coverType[type][i][1];
		int nx = x + coverType[type][i][0];
		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			isSet = false;
		else if ((board[ny][nx] += delta) > 1)
			isSet = false;
	}
	return isSet;
}

//board�� ��� ��ĭ�� ä��� �ִ� ����� ���� ��ȯ
int cover(int board[21][21])
{
	int y = -1, x = -1;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	
	if (y == -1) return 1;
	int ret = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (set(board, y, x, i, 1))
			ret += cover(board);
		set(board, y, x, i, -1);
	}
	return ret;
}

int main()
{
	int C;
	cin >> C;
	for (int testcase = 0; testcase < C; testcase++)
	{
		cin >> H >> W;
		int board[21][21];
		char temp;
		int cnt = 0;
		for (int i = 0; i < H; ++i)
		{
			for (int j = 0; j < W; ++j)
			{
				cin >> temp;
				if (temp == '#')
					board[i][j] = 1;
				else
				{
					board[i][j] = 0; ++cnt;
				}
			}
		}
		if (cnt % 3 != 0)
		{
			cout << 0 << endl;
			continue;
		}
		cout << cover(board) << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}