#include<iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	if (N == 1)
	{
		cout << '*';
		return 0;
	}

	for (int i = 0; i < 2*N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if ((i + j) % 2 == 0)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}


	return 0;
}