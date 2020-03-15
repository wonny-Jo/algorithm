#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int* input = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> input[i];
	int temp;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (input[i] < input[j]) {
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}
	cout << input[N / 2];

	delete input;
	return 0;
}