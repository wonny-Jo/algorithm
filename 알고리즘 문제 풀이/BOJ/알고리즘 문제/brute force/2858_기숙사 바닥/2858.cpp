#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	int R, B;
	cin >> R >> B;
	int total = R + B;
	int sqrtTotal = pow(total, 0.5) + 1;
	for (int i = 2; i < sqrtTotal; ++i)
	{
		int j = total / i;
		if (total % i == 0)
		{
			if ((i - 2) * (j - 2) == B)
			{
				cout << j << ' ' << i;
				return 0;
			}
		}
	}

	return 0;
}