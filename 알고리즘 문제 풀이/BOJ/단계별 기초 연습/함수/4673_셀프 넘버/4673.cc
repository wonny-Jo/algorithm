#include<iostream>
using namespace std;

int Dn(int number)
{
	int sum = number;
	while (true)
	{
		if (number == 0)
			break;
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

bool isSelfNumber(int number)
{
	for (int i = 1; i < number; ++i)
	{
		if (Dn(i) == number)
			return true;
	}
	return false;
}

int main()
{
	for (int i = 1; i <= 10000; ++i)
	{
		if (isSelfNumber(i)==false)
			cout << i << "\n";
	}
	return 0;
}
