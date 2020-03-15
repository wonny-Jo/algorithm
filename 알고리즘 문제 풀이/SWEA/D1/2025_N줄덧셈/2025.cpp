#include<iostream>
using namespace std;

int main() {
	int input, result = 0;
	cin >> input;
	for (int i = 1; i <= input; ++i)
		result += i;
	cout << result;
	return 0;
}