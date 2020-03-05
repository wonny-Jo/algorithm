#include<iostream>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	int sum = 0, min = 10000;
	if ((M == 1&&N>1)||M==2)
	{
		sum += 2;
		min = 2;
		M = 3;
	}
	if (M % 2 == 0)
		++M;
	for (int i = M; i <= N; i+=2)
	{
		int j;
		for (j = 3; j < i; j++)
		{
			if (i%j == 0)
				break;
		}
		if (j == i)
		{
			if (min > i)
				min = i;
			sum += i;
		}
	}
	if (sum == 0)
		cout << -1<<endl;
	else
		cout << sum << endl << min << endl;
	return 0;
}