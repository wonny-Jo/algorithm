#include<iostream>
#include<string.h>
using namespace std;
bool cRow[11][11], cCol[11][11], cBlock[11][11];
int board[11][11];
int cnt = 0;
void print()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			cout << board[i][j] << ' ';
		cout << endl;
	}
}

bool isFull()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] == 0)
				return false;
		}
	}
	return true;
}

void search(int y,int x)
{
	if (cnt == 1)
		return;
	if (isFull())
	{
		++cnt;
		print();
		return;
	}

	for (int i = y; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] == 0)
			{
				for (int k = 1; k <= 9; ++k)
				{
					if (cRow[i][k] == 0 && cCol[j][k] == 0 && cBlock[3 * (i / 3) + (j / 3)][k] == 0)
					{
						board[i][j] = k;
						cRow[i][k] = cCol[j][k] = cBlock[3 * (i / 3) + (j / 3)][k] = 1;
						search(i, j);
						board[i][j] = 0;
						cRow[i][k] = cCol[j][k] = cBlock[3 * (i / 3) + (j / 3)][k] = 0;
					}
				}
				return;
			}
		}
	}
}


int main()
{
	
	memset(cRow, 0, sizeof(cRow));
	memset(cCol, 0, sizeof(cCol));
	memset(cBlock, 0, sizeof(cBlock));
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];
			cRow[i][board[i][j]] = 1;
			cCol[j][board[i][j]] = 1;
			cBlock[3 * (i / 3) + (j / 3)][board[i][j]] = 1;
		}
	}
	search(0,0);

	return 0;
}