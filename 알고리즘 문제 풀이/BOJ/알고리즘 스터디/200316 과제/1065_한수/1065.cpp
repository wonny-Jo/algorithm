#include<iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	int result = 0;
	if (N < 100) //100보다 작은 모든 수는 한수이다.
		result = N;
	else
	{
		result = 99;
		for (int i = 100; i <= N; ++i)
		{
			int temp = i;
			int a = temp % 10;
			temp /= 10;
			int b = temp % 10;
			temp /= 10;
			int dist = b - a;
			a = b;
			while (1)
			{
				if (temp == 0)
				{
					++result;
					break;
				}
				int b = temp % 10;
				temp /= 10;
				if (dist != b - a)
					break;
				a = b;
			}
		}
	}
	cout << result;
	return 0;
}