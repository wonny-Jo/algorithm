#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int input[10];
	int* result = new int[T];
	for (int i = 0; i < T; ++i)
	{
		result[i] = 0;
		for (int j = 0; j < 10; ++j) {
			cin >> input[j]; result[i] += input[j];
		}
		if (result[i] % 10 >= 5)
			result[i] += result[i] % 10;
		result[i] /= 10;
	}
	for (int i = 0; i < T; ++i)
		cout << "#" << i + 1 << " " << result[i] << endl;

	delete result;
	return 0;
}