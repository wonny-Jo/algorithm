#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int input[4];
	for (int i = 0; i < 4; ++i)
		cin >> input[i];
	int num[4] = { 0 };
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			num[i] += input[(i + j) % 4];
			num[i] *= 10;
		}
		num[i] /= 10;
	}
	int minNum = min(min(num[0], num[1]), min(num[2], num[3])); //시계수

	//천단위 계산
	int digit_1000 = minNum / 1000;
	minNum %= 1000;
	int result = 0;
	for (int i = 1; i < digit_1000; ++i)
	{
		result += (10 - i) * (9 - i) * (9 - i);
		result += 45;
		for (int j = 1; j < i; ++j)
			result -= (11 - i);
	}
	//백단위 계산
	int digit_100 = minNum / 100;
	minNum %= 100;
	for (int i = 1; i < digit_100; ++i)
	{
		result += (9 - digit_1000) * (9 - digit_1000);
		result += 10 - i;
	}
	int digit_10 = minNum / 10;
	for (int i = 1; i < digit_10; ++i)
	{
		if (i == 1)
			result += 10 - digit_100;
		else
			result += 9 - digit_1000;
	}
	int digit_1 = minNum % 10;
	if (digit_1000 == digit_10)
		result += digit_1 - digit_100 + 1;
	else
		result += digit_1 - digit_1000;
	cout << result;
	return 0;
}