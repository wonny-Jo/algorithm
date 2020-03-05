#include<iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int searchMax(int a)
{

	int num = a;
	int max = a;
	while (num != 1)
	{
		if (num % 2 == 1)
		{
			num = 3 * num + 1;
			if(max<num)
				max = num;
		}
		else
			num /= 2;
	}
	return max;
}

int main()
{
	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		cout << searchMax(n) << endl;
	}
	return 0;
}