#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie();

	int N; cin >> N;
	int sum = 0;
	int digit = 1;
	int ten = 10;
	while (1)
	{
		if (N < ten)
		{
			sum += digit * (N + 1 - ten / 10);
			break;
		}
		else
			sum += digit * (ten - ten / 10);
		++digit;
		ten *= 10;
	}
	cout << sum;
	return 0;
}