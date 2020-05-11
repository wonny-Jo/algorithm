#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N, K, M; cin >> N >> K >> M;

	int divisor = K % N;
	if (divisor == 0) divisor = N;

	int cnt = 1;
	while (divisor!=M)
	{
		if (M > divisor) M -= divisor;
		else M += N - divisor;

		--N; ++cnt;
		divisor = K % N;
		if (divisor == 0) divisor = N;
	}
	cout << cnt;


	return 0;
}