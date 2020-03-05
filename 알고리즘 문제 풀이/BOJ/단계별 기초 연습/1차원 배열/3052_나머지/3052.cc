#include<iostream>
using namespace std;

int main()
{
	bool b_remainder[42] = { 0 };
	int input,count=0;
	for (int i = 0; i<10; i++)
	{
		cin >> input;
		if (b_remainder[input % 42] == 0)
		{
			b_remainder[input % 42] = 1;
			++count;
		}
	}
	cout <<count;

	return 0;
}