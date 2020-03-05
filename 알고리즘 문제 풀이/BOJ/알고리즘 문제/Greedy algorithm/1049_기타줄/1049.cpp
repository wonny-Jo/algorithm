#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int pac, ind, paci = 1000, indi = 1000;
	for (int i = 0; i < M; i++) {
		cin >> pac >> ind;
		paci = min(pac, paci);
		indi = min(ind, indi);
	}
	if (paci > 6 * indi) { cout << indi * N; }
	else {
		cout << min((N / 6) * paci + (N % 6) * indi, ((N / 6) + 1) * paci) << endl;
	}
}