#include<iostream>
using namespace std;

int main()
{
	int T, N, K;
	int block[15][15];
	cin >> T;
	int length, count;
	for (int i = 0; i < T; i++)
	{
		count = 0;
		cin >> N >> K;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				cin >> block[j][k];

		for (int j = 0; j < N; j++)
		{
			length = 0;
			for (int k = 0; k < N; k++)
			{
				if (block[j][k] == 0 && length != 0)
				{
					if (length == K)
						++count;
					length = 0;
				}
				if (block[j][k] == 1)
					++length;
			}
			if (length == K)
				++count;
		}

		for (int j = 0; j < N; j++)
		{
			length = 0;
			for (int k = 0; k < N; k++)
			{
				if (block[k][j] == 0 && length != 0)
				{
					if (length == K)
						++count;
					length = 0;
				}
				if (block[k][j] == 1)
					++length;
			}
			if (length == K)
				++count;
		}
		cout << "#" << i + 1 << " " << count << endl;
	}


	return 0;
}