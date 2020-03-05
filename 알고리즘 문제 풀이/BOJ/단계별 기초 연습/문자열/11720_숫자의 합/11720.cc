#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int result = 0;
	char numbers[101];
	cin >> numbers;
	for (int i = 0; i<N; i++)
	{
		result+=numbers[i]-'0';
	}
	cout << result;
	return 0;
}