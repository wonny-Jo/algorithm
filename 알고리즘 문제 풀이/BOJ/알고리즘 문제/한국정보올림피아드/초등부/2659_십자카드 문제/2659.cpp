#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int MinClockNum(int input[4])
{
	int num[4] = { 0 };
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			num[i] += input[(i + j) % 4];
			num[i] *= 10;
		}
		num[i] /= 10;
	}
	return min(min(num[0], num[1]), min(num[2], num[3])); //½Ã°è¼ö


}
bool checkMin(int num)
{
	int minNum = num;
	int temp = num;
	for (int i = 0; i < 3; ++i)
	{
		temp = (temp % 1000) * 10 + temp / 1000;
		if (temp < minNum)
			return false;
	}
	return true;
}

int main()
{
	int input[4];
	for (int i = 0; i < 4; ++i)
		cin >> input[i];
	
	int clockNum = MinClockNum(input);
	int cnt = 1;
	for (int i = 1111; i < clockNum; i++)
	{
		if (checkMin(i))
			++cnt;
	}
	cout << cnt;
	
	return 0;
}