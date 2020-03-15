#include<iostream>
using namespace std;

int main() {
	int input;
	cin >> input;
	for (int i = 1; i <= input; ++i)
	{
		if (input % i == 0)
			cout << i << " ";
	}
	return 0;
}