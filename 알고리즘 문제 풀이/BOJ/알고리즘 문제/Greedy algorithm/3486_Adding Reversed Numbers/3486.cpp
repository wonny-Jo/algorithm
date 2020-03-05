#include <iostream>
#include<stack>
using namespace std;

int reversedInt(int num)
{
	int reversedNum = 0;
	while (num != 0)
	{
		reversedNum += num % 10;
		num /= 10;
		reversedNum *= 10;
	}
	reversedNum /= 10;
	return reversedNum;
}


int main()
{
	int N; cin >> N;
	int num[2];
	for (int i = 0; i < N; ++i)
	{
		cin >> num[0] >> num[1];
		int reversedNum[2];
		reversedNum[0] = reversedInt(num[0]);
		reversedNum[1] = reversedInt(num[1]);
		int addReversedNum = reversedNum[0] + reversedNum[1];
		int resultNum = reversedInt(addReversedNum);
		cout << resultNum << endl;
	}

	return 0;
}