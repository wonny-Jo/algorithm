#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int max, min;
	cin >> max >> min;

	if (max < min)
	{
		int temp = max;
		max = min;
		min = temp;
	}
	for (int i = min; i >= 1; --i)
	{
		if (max % i == 0 && min % i == 0)
		{
			cout << i << endl;
			break;
		}
	}
	for (int i = 1; i <= min; ++i)
	{
		if ((max * i) % min == 0)
		{
			cout << max * i << endl;
			break;
		}
	}

	return 0;
}