//1984kb , 0ms

#include<iostream>
using namespace std;

int factorial(int N)
{
	if (N <= 1)
		return 1;
	return factorial(N - 1)*N;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	cout << factorial(N);
	return 0;
}

