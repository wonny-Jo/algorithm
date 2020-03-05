#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	if ((M == 1&&N>1)||M==2)
	{
		cout << 2 << '\n';
		M = 3;
	}
	if (M % 2 == 0)
		++M;
	for (int i = M; i <= N; i+=2)
	{
		int j;
		double sqrt_i = sqrt(i)+0.1;
		for (j = 3; j < sqrt_i; j+=2)
		{
			if (i%j == 0)
				break;
		}
		if (j >= sqrt_i)
		{
			cout << i << '\n';
		}
	}

	return 0;
}