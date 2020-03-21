#include<iostream>
using namespace std;

int arr[1001][1001] = { 0 };

int main()
{
	int N, K; cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		arr[i][0] = 1;
		for (int j = 1; j <= K; ++j)
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j])%10007;
		arr[i][i] = 1;
	}
	cout << arr[N][K];
	
	
	return 0;
}