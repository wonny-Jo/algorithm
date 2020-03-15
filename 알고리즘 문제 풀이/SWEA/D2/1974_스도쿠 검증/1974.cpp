#include<iostream>
//#include<fstream>
using namespace std;
int check_board();
int block[9][9];

int main()
{
	int T;
	cin >> T;
	//ifstream fin("input.txt");
	//fin >> T;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < 9; k++)
				/*fin*/ cin >> block[j][k];
		cout << "#" << i + 1 << " " << check_board() << endl;
	}

	return 0;
}

int check_board()
{
	int check[10];
	for (int j = 0; j < 10; j++)
		check[j] = 0;

	//vertical
	for (int j = 0; j < 9; j++)
	{
		for (int k = 0; k < 9; k++)
			check[block[j][k]] += 1;
		if (!((check[1] == check[2]) && (check[1] == check[3]) && (check[1] == check[4]) && (check[1] == check[5]) &&
			(check[1] == check[6]) && (check[1] == check[7]) && (check[1] == check[8]) && (check[1] == check[9])))
			return 0;
	}

	//horizontal
	for (int j = 0; j < 9; j++)
	{
		for (int k = 0; k < 9; k++)
			check[block[k][j]] += 1;
		if (!((check[1] == check[2]) && (check[1] == check[3]) && (check[1] == check[4]) && (check[1] == check[5]) &&
			(check[1] == check[6]) && (check[1] == check[7]) && (check[1] == check[8]) && (check[1] == check[9])))
			return 0;
	}

	//3x3 block
	for (int y = 0; y < 9; y += 3)
	{
		for (int x = 0; x < 9; x += 3)
		{
			for (int j = y; j < y + 3; j++)
			{
				for (int k = x; k < x + 3; k++)
					check[block[j][k]] += 1;
			}
			if (!((check[1] == check[2]) && (check[1] == check[3]) && (check[1] == check[4]) && (check[1] == check[5]) &&
				(check[1] == check[6]) && (check[1] == check[7]) && (check[1] == check[8]) && (check[1] == check[9])))
				return 0;
		}
	}
	return 1;
}