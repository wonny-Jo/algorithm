#define _CRT_SECURE_NO_WARNINGS
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
			num /= 2;
		}
		else
			num /= 2;
	}
	return max;
}

int main()
{
	int T = 0;
	scanf("%d", &T);
	int n = 0;
	for (int i = 0; i < T; ++i)
	{
		scanf("%d", &n);
		printf("%d\n", searchMax(n));
	}
	return 0;
}