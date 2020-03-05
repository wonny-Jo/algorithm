#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int T, N, a, b;
	cin >> T;
	while (T--)
	{
		cin >> N;
		a = N / 2;

		while (1)
		{
			if (a != 2 && a % 2 == 0)
			{
				--a;
				continue;
			}
			if (a != 2)
			{
				double sqrt_temp = sqrt(a) + 0.1;
				int i;
				for (i = 3; i < sqrt_temp; i += 2)
				{
					if (a%i == 0)
						break;
				}
				if (i < sqrt_temp)
				{
					--a;
					continue;
				}
			}
			b = N - a;
			if (b != 2)
			{
				double sqrt_temp = sqrt(b) + 0.1;
				int i;
				for (i = 3; i < sqrt_temp; i += 2)
				{
					if (b%i == 0)
						break;
				}
				if (i < sqrt_temp)
				{
					--a;
					continue;
				}
			}
			break;
		}
		cout << a << " " << b << endl;
	}
	return 0;
}