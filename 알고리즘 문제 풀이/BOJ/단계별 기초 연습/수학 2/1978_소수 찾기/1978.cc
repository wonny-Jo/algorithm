#include<iostream>
using namespace std;

int main()
{
	int N, number, count = 0;
	cin >> N;
	while (N--)
	{
		cin >> number;
		if (number == 1)
			continue;
		int i;
		for (i = 2; i < number; i++)
		{
			if (number%i == 0)
				break;
		}
		if(i==number)
			++count;
	}
	cout << count << endl;

	return 0;
}