#include<iostream>
using namespace std;

int main() {
	int input;
	int num = 1;
	cin >> input;
	cout << num << " ";
	for (int i = 0; i < input; ++i)
	{
		num *= 2; cout << num << " ";
	}
	return 0;
}