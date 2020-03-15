#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int N, K;
	int point[100][4];
	int temp;
	int rank;
	for (int i = 0; i < T; i++)
	{
		rank = 0;
		cin >> N >> K;
		for (int j = 0; j < N; j++)
		{
			cin >> point[j][0] >> point[j][1] >> point[j][2];
			point[j][3] = 35 * point[j][0] + 45 * point[j][1] + 20 * point[j][2];
		}
		temp = point[K - 1][3];
		for (int j = 0; j < N; j++)
		{
			if (temp < point[j][3])
				++rank;
		}
		cout << "#" << i + 1 << " ";
		switch (rank * 10 / N)
		{
		case 0: cout << "A+" << endl; break;
		case 1: cout << "A0" << endl; break;
		case 2: cout << "A-" << endl; break;
		case 3: cout << "B+" << endl; break;
		case 4: cout << "B0" << endl; break;
		case 5: cout << "B-" << endl; break;
		case 6: cout << "C+" << endl; break;
		case 7: cout << "C0" << endl; break;
		case 8: cout << "C-" << endl; break;
		case 9: cout << "D0" << endl; break;
		default: break;
		}
	}

	return 0;
}