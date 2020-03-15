#include<iostream>
using namespace std;

int main() {
	int T; cin >> T;
	int input;
	int* result = new int[T];
	for (int i = 0; i < T; ++i)
	{
		result[i] = 0;
		for (int j = 0; j < 10; ++j)
		{
			cin >> input;
			result[i] += (input % 2 == 1 ? input : 0);
		}
	}
	for (int i = 0; i < T; ++i)
		cout << "#" << i + 1 << " " << result[i] << endl;
	return 0;
}