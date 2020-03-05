#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	char input;
	bool maskA[51][51] = { 0 };
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> input;
			maskA[i][j] = input - '0';
		}
	bool maskB[51][51] = { 0 };
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> input;
			maskB[i][j] = input - '0';
		}
	int count = 0;
	for (int i = 0; i < N-2; ++i)
		for (int j = 0; j < M-2; ++j)
		{
			if (maskA[i][j] != maskB[i][j])
			{
				++count;
				for (int a = 0; a < 3; ++a)
					for (int b = 0; b < 3; ++b)
						maskA[i + a][j + b] = !maskA[i + a][j + b];
			}
		}

	bool hasResult = true;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			if (maskA[i][j] != maskB[i][j])
				hasResult = false;
		}

	if (hasResult)
		cout << count;
	else
		cout << -1;
	return 0;
}