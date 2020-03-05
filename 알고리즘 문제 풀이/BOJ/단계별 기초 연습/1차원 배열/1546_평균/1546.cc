#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int max = 0;
	double average = 0;
	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		average += input;
		if (max < input)
			max = input;
	}
	average = average * 100 / (N*max);
	cout << average;

	return 0;
}