#include<iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int coin[11];
	for (int i = 0; i < N; ++i)
		cin >> coin[i];
	int coinNum[11] = { 0 };
	for (int i = N-1; i >= 0; --i)
	{
		coinNum[i] = K / coin[i];
		K %= coin[i];
	}
	int sum = 0;
	for (int i = 0; i < N; ++i)
		sum += coinNum[i];
	cout << sum << endl;
	return 0;
}