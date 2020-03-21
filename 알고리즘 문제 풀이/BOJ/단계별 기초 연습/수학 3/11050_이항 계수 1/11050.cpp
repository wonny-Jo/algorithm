#include<iostream>
using namespace std;

int main()
{
	int N, K; cin >> N >> K;
	int result = 1;
	for (int i = 0; i < K; ++i)
		result *= N - i;
	for (int i = 2; i <= K; ++i)
		result /= i;
	cout << result;

	return 0;
}