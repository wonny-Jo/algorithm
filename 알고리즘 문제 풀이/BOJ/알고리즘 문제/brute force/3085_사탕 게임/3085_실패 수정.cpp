#include<iostream>
#include<algorithm>
using namespace std;
int N;
int max(int a, int b)
{
	return a > b ? a : b;
}

int row_check(string board[51], int i)
{
	int max_count = 1;
	int count = 1;
	for (int k = 1; k < N; ++k)
	{
		if (board[i][k] == board[i][k - 1])
		{
			++count;
			max_count = max(max_count, count);
		}
		else
			count = 1;
	}
	return max_count;
}

int column_check(string board[51], int j)
{
	int max_count = 1;
	int count = 1;
	for (int k = 1; k < N; ++k)
	{
		if (board[k][j] == board[k - 1][j])
		{
			++count;
			max_count = max(max_count, count);
		}
		else
			count = 1;
	}
	return max_count;
}

int main()
{
	cin >> N;
	string board[51];
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	int max_count = 0;

	for (int i = 0; i < N; ++i)
	{
		max_count = max(max_count, row_check(board, i));
		max_count = max(max_count, column_check(board, i));
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - 1; ++j)
		{
			if (board[i][j] != board[i][j + 1]) //�翷���� �ٲٴ� ���
			{
				swap(board[i][j], board[i][j + 1]);
				//�������� üũ
				max_count = max(max_count, row_check(board, i));
				//�� üũ�� �����ؾߵ�
				max_count = max(max_count, column_check(board, j));
				max_count = max(max_count, column_check(board, j + 1));

				swap(board[i][j], board[i][j + 1]);
			}
			if (board[j][i] != board[j + 1][i])//���Ʒ��� �ٲٴ� ���
			{
				swap(board[j][i], board[j + 1][i]);
				//������� üũ
				max_count = max(max_count, column_check(board, i));
				//�� üũ�� �����ؾߵ�
				max_count = max(max_count, row_check(board, j));
				max_count = max(max_count, row_check(board, j + 1));

				swap(board[j][i], board[j + 1][i]);
			}
		}
	}
	cout << max_count;

	return 0;
}