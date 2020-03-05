#include<iostream>
using namespace std;

int main()
{
	string board;
	cin >> board;
	int size = board.size();
	for (int i = 0; i < size; ++i)
	{
		int count = 0;
		int j = i;
		while (board[j] == 'X')
		{
			++j;
			++count;
			if (count == 4)
			{
				for (int k = i; k < i+4; ++k)
					board[k] = 'A';
				i += 3;
				break;
			}
		}
		if (count % 2 == 1)
		{
			cout << -1;
			return 0;
		}
		if (count == 2)
		{
			for (int k = i; k < i+2; ++k)
				board[k] = 'B';
			i += 1;
		}
	}
	cout << board;
	return 0;
}