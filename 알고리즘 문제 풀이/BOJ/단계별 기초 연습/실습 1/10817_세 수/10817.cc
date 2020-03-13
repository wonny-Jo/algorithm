#include<iostream>
using namespace std;

int main()
{
	int num[3];
	cin >> num[0] >> num[1] >> num[2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (num[j] < num[j+1])
			{
				int temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}
	cout << num[1];
	return 0;
}
