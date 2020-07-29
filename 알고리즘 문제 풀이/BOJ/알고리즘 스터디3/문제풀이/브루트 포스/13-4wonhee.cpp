//1988kb, 0ms
#include<iostream>
using namespace std;
char board[51][51];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, M; cin >> N >> M;
	int min = 64;
	for (int i = 0; i < N; i++)
		cin >> board[i];

	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			int count = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if ((k + l) % 2 == 0)
					{
						if (board[i + k][j + l] == 'W')
							++count;
					}
					else
					{
						if (board[i + k][j + l] == 'B')
							++count;
					}
				}
			}
			if (count > 32)
				count = 64 - count;
			if (count < min)
				min = count;
		}
	}
	cout << min;

	return 0;
}