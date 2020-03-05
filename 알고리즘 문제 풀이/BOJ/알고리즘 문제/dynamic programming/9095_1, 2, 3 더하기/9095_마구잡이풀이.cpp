//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;


int calcCombination(int total, int some)
{
	int n = total;
	int r = (total - some > some) ? some : total - some;

	int ret = 1;
	for (int i = 0; i < r; ++i)
		ret *= (n - i);
	for (int i = 0; i < r; ++i)
		ret /= (i + 1);
	return ret;
}


int calcSubCase(int three, int two, int one)
{
	int total = three + two + one;
	return calcCombination(total, three) * calcCombination(total - three, two) * calcCombination(total - three - two, one);
}

int searchSubCase(int num)
{
	int three = 0, two = 0, one = 0;
	int total = num;
	three = total / 3;
	total %= 3;
	if (total == 2)
		two = 1;
	else
		one = total;
	int sum = calcSubCase(three, two, one);
	while (one!=num)
	{
		if (two)
		{
			--two; one += 2;
		}
		else if (three)
		{
			--three; ++two;++one;
			two += one / 2;
			one %= 2;
		}

		sum += calcSubCase(three, two, one);
	}
	return sum ;
}


int main()
{
	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		cout << searchSubCase(n) << endl;;
	}
	return 0;
}