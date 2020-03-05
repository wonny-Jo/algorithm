#include<iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int N, M; cin >> N >> M;
	string arr[51];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	int size = min(N, M);
	while (size>1)
	{
		for (int i = 0; i <= N-size; ++i)
		{
			for (int j = 0; j <= M-size; ++j)
			{
				if (arr[i][j] == arr[i][j + size - 1] && arr[i][j] == arr[i + size - 1][j] && arr[i][j] == arr[i + size - 1][j + size - 1])
				{
					cout << size * size;
					return 0;
				}
			}
		}
		--size;
	}
	cout << 1;

	return 0;
}