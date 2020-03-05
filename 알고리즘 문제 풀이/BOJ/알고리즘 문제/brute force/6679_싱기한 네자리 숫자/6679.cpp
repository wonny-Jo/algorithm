#include<iostream>
using namespace std;


int main()
{
	for (int i = 1000; i < 10000; ++i)
	{
		int temp10 = i, temp12 = i, temp16 = i;
		int sum10 = 0, sum12 = 0, sum16 = 0;
		for (int j = 0; j < 4; ++j)
		{
			sum10 += temp10 % 10;
			temp10 /= 10;
		}
		for (int j = 0; j < 4; ++j)
		{
			sum12 += temp12 % 12;
			temp12 /= 12;
		}
		if (sum10 != sum12)
			continue;
		for (int j = 0; j < 4; ++j)
		{
			sum16 += temp16 % 16;
			temp16 /= 16;
		}
		if (sum12 == sum16)
			cout << i << endl;
	}

	return 0;
}