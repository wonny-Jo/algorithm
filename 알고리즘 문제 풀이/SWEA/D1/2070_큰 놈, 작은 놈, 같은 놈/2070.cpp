#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int input[2];
	char* result = new char[T];
	for (int i = 0; i < T; ++i)
	{
		for (int j = 0; j < 2; ++j)
			cin >> input[j];
		if (input[0] > input[1])
			result[i] = '>';
		else if (input[0] == input[1])
			result[i] = '=';
		else
			result[i] = '<';
	}
	for (int i = 0; i < T; ++i)
		cout << "#" << i + 1 << " " << result[i] << endl;

	delete result;
	return 0;
}