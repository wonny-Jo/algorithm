#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int M, N;
	int count;
	cin >> M;
	while (M)
	{
		count = 0;
		N = 2 * M; M += 1;
		if (M == 2)
		{
			++count;
			++M;
		}
		if (M % 2 == 0)
			++M;
		for (int i = M; i <= N; i += 2)
		{
			int j;
			double sqrt_i = sqrt(i) + 0.1;
			for (j = 3; j < sqrt_i; j += 2)
			{
				if (i%j == 0)
					break;
			}
			if (j >= sqrt_i)
			{
				++count;
			}
		}
		cout << count << endl;
		cin >> M;
	}
	return 0;
}