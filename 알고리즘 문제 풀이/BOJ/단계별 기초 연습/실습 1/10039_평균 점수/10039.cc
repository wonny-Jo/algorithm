#include<iostream>
using namespace std;

int main()
{
	int point[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> point[i];
		if (point[i] < 40)
			point[i] = 40;
	}
	cout << (point[0] + point[1] + point[2] + point[3] + point[4]) / 5;
	return 0;
}
