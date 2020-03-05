#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int cycleNum = N;
	int cycleCount = 0;
	while (true)
	{
		if (cycleNum<10)
			cycleNum *= 11;
		else
		{
			int sum = (cycleNum / 10 + cycleNum % 10)%10;
			cycleNum = (cycleNum % 10) * 10 + sum;
		}
		++cycleCount;
		if (cycleNum == N)
			break;
	}
	cout << cycleCount;
	return 0;
}
