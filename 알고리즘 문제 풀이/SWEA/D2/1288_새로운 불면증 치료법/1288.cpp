#include<iostream>
using namespace std;

int main()
{

	int T, number;
	int count, numberxN;
	bool checkNum[10] = { 0 };
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> number;
		count = 1;
		for (int i = 0; i < 10; i++)
			checkNum[i] = 0;
		while (1)
		{
			numberxN = number * count;
			while (numberxN > 0)
			{
				checkNum[numberxN % 10] = 1;
				numberxN /= 10;
			}
			if (checkNum[0] == 1 && checkNum[1] == 1 && checkNum[2] == 1 && checkNum[3] == 1 && checkNum[4] == 1 &&
				checkNum[5] == 1 && checkNum[6] == 1 && checkNum[7] == 1 && checkNum[8] == 1 && checkNum[9] == 1)
				break;
			++count;
		}
		cout << "#" << test_case << " " << number * count << endl;
	}
	return 0;
}