//1974kb, 0ms
#include<iostream>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	int data[100];
	int diff, min = 300000;
	for (int i = 0; i < N; i++)
		cin >> data[i];
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				diff = M - (data[i] + data[j] + data[k]);
				if (diff >= 0 && diff < min)
					min = diff;
			}
		}
	}
	cout << M - min;

	return 0;
}