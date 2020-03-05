#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}

int calcArea(int leftDown_x, int leftDown_y, int rightUp_x, int rightUp_y)
{
	int x_length = rightUp_x - leftDown_x;
	int y_length = rightUp_y - leftDown_y;
	if (x_length < 0 || y_length < 0)
		return 0;
	return x_length * y_length;
}



int main()
{
	bool c[101][101] = { 0 };
	int input[4];
	for (int i = 0; i < 4; ++i)
	{
		cin >> input[0] >> input[1] >> input[2] >> input[3];
		for (int j = input[1]; j < input[3]; ++j)
		{
			for (int k = input[0]; k < input[2]; ++k)
				c[j][k] = true;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 100; ++i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (c[i][j])
				++cnt;
		}
	}
	cout << cnt;
	return 0;
}