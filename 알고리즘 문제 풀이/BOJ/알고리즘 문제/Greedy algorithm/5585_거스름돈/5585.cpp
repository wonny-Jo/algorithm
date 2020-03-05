#include <iostream>
using namespace std;

int main()
{
	int num = 1000;
	int pay; cin >> pay;
	num -= pay;

	int count = 0;
	count += num / 500;
	num %= 500;
	count += num / 100;
	num %= 100;
	count += num / 50;
	num %= 50;
	count += num / 10;
	num %= 10;
	count += num / 5;
	num %= 5;
	count += num / 1;
	cout << count;
	return 0;
}