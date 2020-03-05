#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	long long N;
	cin >> N;
	long long i = 666, count = 0;
	long long temp = i;
	while (true)
	{
		if (temp % 1000 == 666)
		{
			++count;
			if (count == N)
			{
				cout << i;
				return 0;
			}
			temp = ++i;
			continue;
		}
		temp /= 10;
		if (!temp)
			temp = ++i;
	}

	return 0;
}