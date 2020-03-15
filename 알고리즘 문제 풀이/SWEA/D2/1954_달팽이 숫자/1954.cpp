#include<iostream>
using namespace std;

int main()
{
	int T, N;
	cin >> T;
	int count;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int** table = new int* [N];
		for (int j = 0; j < N; j++)
			table[j] = new int[N];
		count = 1;
		int end = N * N + 1;
		int a = 0, b = 0;
		table[0][0] = count++;
		for (int j = 1; j < N; j++)
		{
			++b;
			table[a][b] = count++;
		}
		for (int j = N - 1; j > 0; j -= 2)
		{
			for (int row = 1; row <= j; row++)
			{
				++a;
				table[a][b] = count++;
			}
			for (int col = 1; col <= j; col++)
			{
				--b;
				table[a][b] = count++;
			}
			for (int row = 1; row <= j - 1; row++)
			{
				--a;
				table[a][b] = count++;
			}
			for (int col = 1; col <= j - 1; col++)
			{
				++b;
				table[a][b] = count++;
			}
		}
		cout << "#" << i + 1 << endl;
		for (int col = 0; col < N; col++) {
			for (int row = 0; row < N; row++)
				cout << table[col][row] << " ";
			cout << endl;
		}
	}
	return 0;
}