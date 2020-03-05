#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int N;
	cin >> N;
	int temp, result;
	for (int i = 1; i < N; i++)
	{
		temp = i;
		result = temp;
		while (temp)
		{
			result += temp % 10;
			temp /= 10;
		}
		if (result == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}