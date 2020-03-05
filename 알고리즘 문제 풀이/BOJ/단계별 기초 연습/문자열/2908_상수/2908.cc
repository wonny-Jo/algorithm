#include<iostream>
using namespace std;


int main()
{
	int A, B;
	cin >> A >> B;
	int _A = A, _B = B;
	bool isA;
	for (int i = 0; i < 3; ++i)
	{
		if (_A % 10>_B % 10)
		{
			isA = true;
			break;
		}
		else if (_A % 10 < _B % 10)
		{
			isA = false;
			break;
		}
		_A /= 10; _B /= 10;
	}
	int result=0;
	if (isA==true)
	{
		for (int i = 0; i < 3; ++i)
		{
			result += A % 10;
			A /= 10;
			if (A != 0)
				result *= 10;
		}
	}
	else
	{
		for (int i = 0; i < 3; ++i)
		{
			result += B % 10;
			B /= 10;
			if (B != 0)
				result *= 10;
		}
	}
	cout << result;
	return 0;
}
