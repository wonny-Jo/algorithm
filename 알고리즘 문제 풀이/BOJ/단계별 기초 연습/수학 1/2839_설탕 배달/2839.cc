#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int num5 = N / 5;
	int num3;
	if (N % 5 == 0)
	{
		cout << num5;
		return 0;
	}
	while (true)
	{
		if ((N - 5 * num5) % 3 == 0)
		{
			cout << num5 + ((N - 5 * num5) / 3);
			break;
		}
		--num5;
		if (num5 < 0)
		{
			cout << -1;
			break;
		}
	}
	return 0;
}