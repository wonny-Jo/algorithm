#include<iostream>
using namespace std;

int main() {
	int T; cin >> T;
	int num_test;
	int input;
	int** result = new int* [T];
	for (int i = 0; i < T; ++i)
	{
		result[i] = new int[101];
		for (int j = 0; j < 101; ++j)
			result[i][j] = 0;
	}
	for (int i = 0; i < T; ++i)
	{
		cin >> num_test;
		for (int j = 0; j < 1000; ++j) {
			cin >> input; ++result[i][input];
		}
	}
	int max, max_pos;
	for (int i = 0; i < T; ++i) {
		max = 0;
		for (int j = 0; j < 101; ++j) {
			if (max <= result[i][j]) {
				max = result[i][j]; max_pos = j;
			}
		}
		cout << "#" << i + 1 << " " << max_pos << endl;
	}
	for (int i = 0; i < T; ++i)
		delete result[i];
	delete result;
	return 0;
}