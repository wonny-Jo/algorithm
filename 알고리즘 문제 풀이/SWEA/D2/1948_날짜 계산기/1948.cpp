#include<iostream>
using namespace std;

int monthTable[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int T;
	int month[2], day[2];
	cin >> T;
	int diff = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> month[0] >> day[0] >> month[1] >> day[1];
		if (month[0] == month[1])
			diff = day[1] - day[0] + 1;
		else
		{
			diff = monthTable[month[0]] - day[0] + 1;
			for (int i = month[0] + 1; i < month[1]; i++)
				diff += monthTable[i];
			diff += day[1];
		}
		cout << "#" << i + 1 << " " << diff << endl;
	}

	return 0;
}