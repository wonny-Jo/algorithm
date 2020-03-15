#include<iostream>
using namespace std;

int multiple(int* A, int* B, int smallNum)
{
	int result = 0;
	for (int i = 0; i < smallNum; i++)
		result += A[i] * B[i];
	return result;
}

int main()
{
	int T;
	cin >> T;
	int N, M;
	int matrixA[20], matrixB[20];
	int max;
	for (int i = 0; i < T; i++)
	{
		max = 0;
		cin >> N >> M;
		for (int j = 0; j < N; j++)
			cin >> matrixA[j];
		for (int j = 0; j < M; j++)
			cin >> matrixB[j];
		if (N == M)
			max = multiple(matrixA, matrixB, N);
		else if (N > M)
		{
			for (int j = 0; j < N - M + 1; j++)
			{
				if (max < multiple(&matrixA[j], matrixB, M))
					max = multiple(&matrixA[j], matrixB, M);
			}
		}
		else
		{
			for (int j = 0; j < M - N + 1; j++)
			{
				if (max < multiple(matrixA, &matrixB[j], N))
					max = multiple(matrixA, &matrixB[j], N);
			}
		}
		cout << "#" << i + 1 << " " << max << endl;
	}


	return 0;
}