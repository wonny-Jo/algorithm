#include<iostream>
using namespace std;
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int N; cin >> N;
	int RGB[3];
	int cost[3][1001] = { 0 };
	for (int i = 1; i <= N; ++i)
	{
		cin >>RGB[0]>>RGB[1]>>RGB[2];
		for (int j = 0; j < 3; ++j)
			cost[j][i] = RGB[j] + min(cost[(j+1)%3][i - 1], cost[(j+2)%3][i - 1]);
	}
	int minResult = min(cost[0][N], cost[1][N]);
	minResult = min(minResult, cost[2][N]);
	cout << minResult;
	return 0;
}