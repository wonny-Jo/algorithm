#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int N, M;
	cin >> N >> M;
	int data[100], diff,min = 300000;
	for (int i = 0; i < N; i++)
		cin >> data[i];
	for (int i = 0; i < N-2; i++)
	{
		for (int j = i+1; j < N-1; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				diff = M -( data[i] + data[j] + data[k]);
				if (diff>=0&&diff < min)
					min = diff;
			}
		}
	}
	cout << M - min;

	return 0;
}