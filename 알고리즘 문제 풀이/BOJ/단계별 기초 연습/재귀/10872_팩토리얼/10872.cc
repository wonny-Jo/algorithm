#include<iostream>
using namespace std;
//int factorial(int);
//int main()
//{
//	int N;
//	cin >> N;
//	cout << factorial(N);
//	return 0;
//}
//
//int factorial(int N)
//{
//	if (N == 1)
//		return 1;
//	return factorial(N - 1)*N;
//}

int main()
{
	int N;
	cin >> N;
	int result = 1;
	for (int i = 1; i <= N; i++)
	{
		result *= i;
	}
	cout << result;

	return 0;
}