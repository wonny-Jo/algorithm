#include<iostream>
#include<string.h>
using namespace std;
int result[1000001];

void fibonacci(int N)
{
	result[1] = 1; result[2] = 2;
	for (int i = 3; i <= N; i++)
		result[i] = (result[i - 1] + result[i - 2]) % 15746;
}


int main()
{
	int N;
	cin >> N;
	memset(result, -1, sizeof(result));
	fibonacci(N);
	cout<<result[N];
	
	return 0;
}