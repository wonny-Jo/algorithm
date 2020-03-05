#include<iostream>
#include<cmath>
using namespace std;

int fibonacci(int n_1, int n, int N);

int main()
{
	int N;
	cin >> N;
	cout << fibonacci(0, 1, N);

	return 0;
}

int fibonacci(int n_1, int n, int N)
{
	if (N == 0)
		return n_1;
	return fibonacci(n, n + n_1, --N);
}