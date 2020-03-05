#include<iostream>
using namespace std;


void fibonacci(int n)
{
	int first[2] = { 0 };
	int second[2] = { 0 };
	if (n == 0)
	{
		++first[0];
	}
	else
	{
		for (int i = 0; i <= n; ++i)
		{
			if (i == 0)
				++second[0];
			else if (i == 1)
				++first[1];
			else
			{
				int temp[2] = { first[0], first[1] };
				first[0] += second[0];
				first[1]+= second[1];
				second[0] = temp[0];
				second[1]=	temp[1];
			}
		}
	}
	cout << first[0] << " " << first[1] << endl;
}


int main()
{
	int testNum;
	cin >> testNum;
	int* input = new int[testNum];
	for (int i = 0; i < testNum; ++i)
	{
		cin >> input[i];
	}
	for (int i = 0; i < testNum; ++i)
	{
		fibonacci(input[i]);
	}
}