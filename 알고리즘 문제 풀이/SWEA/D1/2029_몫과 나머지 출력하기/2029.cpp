#include<iostream>
using namespace std;

int main() {
	int T; cin >> T;
	int* inputA = new int[T], * inputB = new int[T];
	for (int i = 0; i < T; ++i)
		cin >> inputA[i] >> inputB[i];

	for (int i = 0; i < T; ++i)
		cout << "#" << i + 1 << " " << inputA[i] / inputB[i] << " " << inputA[i] % inputB[i] << endl;

	delete inputA; delete inputB;
	return 0;
}