#include <iostream>
using namespace std;

int main() {
	int inputA, inputB;
	cin >> inputA >> inputB;
	if (inputA == 1)
	{
		if (inputB == 2)
			cout << "B";
		else
			cout << "A";
	}
	else if (inputA == 2)
	{
		if (inputB == 3)
			cout << "B";
		else
			cout << "A";
	}
	else
	{
		if (inputB == 1)
			cout << "B";
		else
			cout << "A";
	}
	return 0;
}