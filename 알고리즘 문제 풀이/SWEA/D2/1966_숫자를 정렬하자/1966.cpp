#include<iostream>
using namespace std;

int main()
{
	int T, N;
	int data[50];
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
			cin >> data[j];
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N - 1; k++)
			{
				if (data[k] > data[k + 1])
				{
					int temp = data[k];
					data[k] = data[k + 1];
					data[k + 1] = temp;
				}
			}
		}
		cout << "#" << i + 1;
		for (int j = 0; j < N; j++)
			cout << " " << data[j];
		cout << endl;
	}


	return 0;
}