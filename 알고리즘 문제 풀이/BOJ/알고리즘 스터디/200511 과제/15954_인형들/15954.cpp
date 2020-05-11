#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
long double num[501];
long double dp[501][501] = { 0 }; //i에서 j까지의 수의 합
long double minDev = 9876543210;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	if (K == 1)
	{
		cout << 0;
		return 0;
	}
	
	for (int i = 0; i < N; i++)
	{
		dp[i][i] = num[i];
		for (int j = i+1; j < N; j++)
		{
			dp[i][j] = dp[i][j - 1] + num[j];
			if (j - i + 1 < K)
				continue;

			long double m = dp[i][j] / (j - i + 1);
			long double dev = 0;
			for (int k = i; k <= j; k++)
				dev += pow((num[k] - m), 2);
			dev /= (j - i + 1); dev = pow(dev, 0.5);
			minDev = min(minDev, dev);
		}
	}
	cout.setf(ios::fixed);
	cout.precision(11);
	cout << minDev;

	return 0;
}
