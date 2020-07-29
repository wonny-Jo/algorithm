//1984kb, 0ms
#include<iostream>
using namespace std;

int fibonacci(int n_1, int n, int N)
{
	if (N == 0)
		return n_1;
	return fibonacci(n, n + n_1, N-1);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	cout << fibonacci(0, 1, N);

	return 0;
}

