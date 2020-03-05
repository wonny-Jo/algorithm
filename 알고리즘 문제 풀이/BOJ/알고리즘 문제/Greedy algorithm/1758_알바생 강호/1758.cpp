#include<iostream>
#include<algorithm>
using namespace std;

bool compare(long long a, long long b)
{
	return a > b;
}

int main()
{
	long long N;
	cin >> N;
	long long tip[100001] = { 0 };
	for (long long i = 0; i < N; ++i)
		cin >> tip[i];
	sort(tip, tip + N, compare);
	long long sum = 0;
	long long temp;
	for (long long i = 0; i < N; ++i)
	{
		temp = tip[i] - i;
		if (temp <= 0)
			break;
		sum += temp;
	}
	cout << sum;

	return 0;
}