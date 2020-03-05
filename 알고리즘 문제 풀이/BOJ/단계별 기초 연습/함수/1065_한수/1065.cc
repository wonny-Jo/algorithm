#include<iostream>
using namespace std;

int seqCount(int number)
{
	int count = 0;
	for (int i = 1; i <= number; ++i)
	{
		if (i < 100)
			++count;
		else if (i >= 111&&i<1000)
		{
			int num = i;
			int digitNum[3];
			digitNum[0] = num % 10;
			num /= 10;
			digitNum[1] = num % 10;
			num /= 10;
			digitNum[2] = num;
			if (digitNum[2]+digitNum[0]==2*digitNum[1])
				++count;
		}
	}
	return count;
}

int main()
{
	int N;
	cin >> N;
	cout << seqCount(N);
	return 0;
}
