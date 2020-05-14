#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int N, A[21][21];
int region[21][21] = { 0 };
int totalNum[6];

int findRegion(int y, int x, int d1, int d2)
{
	for (int i = 1; i <= 5; i++)
		totalNum[i] = 0;
	memset(region, 0, sizeof(region));
	//5�� ��ġ���� ����
	int r_up = y, r_bottom = y, c = x;
	for (int i = 0; i <= d1+d2; i++)
	{
		for (int r = r_up; r <= r_bottom; r++)
		{
			region[r][c] = 5;
			totalNum[5] += A[r][c];
		}
		//r_up ������Ʈ
		if (i < d1) --r_up;
		else ++r_up;
		//r_bottom ������Ʈ
		if (i < d2) ++r_bottom;
		else --r_bottom;
		//c������Ʈ
		++c;
	}

	//���� 1
	for (int r = 1; r < y; r++)
		for (int c = 1; c <= x + d1; c++)
		{
			if (region[r][c] != 5)
			{
				region[r][c] = 1;
				totalNum[1] += A[r][c];
			}
		}
	//���� 2
	for (int r = 1; r <= y-d1+d2; r++)
		for (int c = x+d1+1; c <= N; c++)
		{
			if (region[r][c] != 5)
			{
				region[r][c] = 2;
				totalNum[2] += A[r][c];
			}
		}
	//���� 3
	for (int r = y; r <= N; r++)
		for (int c = 1; c <x+d2; c++)
		{
			if (region[r][c] != 5)
			{
				region[r][c] = 3;
				totalNum[3] += A[r][c];
			}
		}
	//���� 4
	for (int r =y-d1+d2+1; r <= N; r++)
		for (int c = x+d2; c <= N; c++)
		{
			if (region[r][c] != 5)
			{
				region[r][c] = 4;
				totalNum[4] += A[r][c];
			}
		}

	sort(totalNum + 1, totalNum + 6);
	return totalNum[5] - totalNum[1];
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> A[i][j];

	int ret = 400000;
	//d1�� 1���� Ŀ���ϹǷ� y�� 2���� ����,N-1����
	//d1+d2�� 2���� Ŀ���ϹǷ� x�� 1���� N-2������
	for (int y = 2; y <= N-1; y++)
	{
		for (int x = 1; x <= N-2; x++)
		{
			//d1�� y���ʰ� x�������� ���� ������ ���� �� ����
			int d1_size = min(y-1, N - x - 1);//x�� d2�� �ּҵ� ���ܾ��ϹǷ� -1�� ����
			for (int d1 = 1; d1 <= d1_size; d1++)
			{
				//d2�� y�Ʒ��ʰ� x�������� ���� ������ ���� �� ����
				int d2_size = min(N - y, N - x - d1);
				for (int d2 = 1; d2 <= d2_size; d2++)
					ret = min(ret, findRegion(y, x, d1, d2));
			}
		}
	}
	cout << ret;

	return 0;
}