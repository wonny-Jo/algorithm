#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int temp = b;
	cout << a * (temp % 10) << endl;
	temp /= 10;
	cout << a * (temp % 10) << endl;
	temp /= 10;
	cout << a * (temp % 10) << endl;
	cout << a * b << endl;

	return 0;
}