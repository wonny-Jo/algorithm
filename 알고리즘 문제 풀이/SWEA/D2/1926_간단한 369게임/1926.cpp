#include<iostream>
using namespace std;

int main()
{
	int input; cin >> input;
	int clapNum;
	int checkNum;
	for (int i = 1; i <= input; ++i)
	{
		clapNum = 0; checkNum = i;
		while (checkNum > 0)
		{
			if (checkNum % 10 == 3 || checkNum % 10 == 6 || checkNum % 10 == 9)
				++clapNum;
			checkNum /= 10;
		}
		if (clapNum == 0)
			cout << i << " ";
		else
		{
			for (int j = 0; j < clapNum; ++j)
				cout << "-";
			cout << " ";
		}
	}

	return 0;
}