#include<iostream>
using namespace std;

int main()
{
	int T, number;
	int a, b, c, d, e;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> number;
		a = b = c = d = e = 0;
		while (number % 2 == 0)
		{
			number /= 2;
			++a;
		}
		while (number % 3 == 0)
		{
			number /= 3;
			++b;
		}
		while (number % 5 == 0)
		{
			number /= 5;
			++c;
		}
		while (number % 7 == 0)
		{
			number /= 7;
			++d;
		}
		while (number % 11 == 0)
		{
			number /= 11;
			++e;
		}
		cout << "#" << i + 1 << " " << a << " " << b << " " << c << " " << d << " " << e << endl;
	}

	return 0;
}