#include<iostream>
using namespace std;

int main()
{
	int T, N;
	int remain[8];
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		remain[0] = N / 50000;
		N %= 50000;
		remain[1] = N / 10000;
		N %= 10000;
		remain[2] = N / 5000;
		N %= 5000;
		remain[3] = N / 1000;
		N %= 1000;
		remain[4] = N / 500;
		N %= 500;
		remain[5] = N / 100;
		N %= 100;
		remain[6] = N / 50;
		N %= 50;
		remain[7] = N / 10;

		cout << "#" << i + 1 << endl;
		for (int j = 0; j < 8; j++)
			cout << remain[j] << " ";
		cout << endl;
	}

	return 0;
}