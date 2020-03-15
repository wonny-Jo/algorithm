#include<iostream>
using namespace std;

int main()
{
	int T, N;
	char alphabet;
	int numAlpha, count;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		count = 0;
		cout << "#" << i + 1 << endl;
		for (int j = 0; j < N; j++)
		{
			cin >> alphabet >> numAlpha;

			for (int k = 0; k < numAlpha; k++)
			{
				cout << alphabet;
				++count;
				if (count == 10)
				{
					count = 0;
					cout << endl;
				}
			}
		}
		cout << endl;
	}

	return 0;
}