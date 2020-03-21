#include<iostream>
using namespace std;

int get_gcd(int a, int b)
{
	int min = a < b ? a : b;
	for (int i = min; i >= 1; --i)
	{
		if (a % i == 0 && b % i == 0)
			return i;
	}
}

int main()
{
	int N; cin >> N;
	int arr[101];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 1; i < N; ++i)
	{
		int gcd = get_gcd(arr[0], arr[i]);
		cout << arr[0] / gcd << '/' << arr[i] / gcd << endl;
	}

	return 0;
}