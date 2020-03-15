#include<iostream>
using namespace std;

int main() {
	int T; cin >> T;
	int P, Q, R, S, W;
	int* result = new int[T];
	int feeA, feeB;
	for (int i = 0; i < T; ++i)
	{
		cin >> P >> Q >> R >> S >> W;
		feeA = P * W;
		feeB = Q + (W < R ? 0 : (W - R) * S);
		result[i] = feeA > feeB ? feeB : feeA;
	}
	for (int i = 0; i < T; ++i)
		cout << "#" << i + 1 << " " << result[i] << endl;

	return 0;
}