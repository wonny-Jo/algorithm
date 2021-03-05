#include<iostream>
////////////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1000001][2] = { 0 };

int solution(vector<int> money) {
	
	dp[0][0] = money[0];
	dp[1][0] = money[0];
	dp[1][1] = money[1];
	int Size = money.size();
	for (int i = 2; i < Size-1; i++)
	{
		dp[i][0] = max(dp[i - 2][0] + money[i], dp[i - 1][0]);
		dp[i][1] = max(dp[i - 2][1] + money[i], dp[i - 1][1]);
	}
	dp[Size - 1][1] = max(dp[Size - 3][1] + money[Size - 1], dp[Size - 1][1]);
	return max(dp[Size-1][1],dp[Size-2][0]);
}
////////////////////////////////////////////////

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cout << solution({ 1000, 1, 0, 1, 2, 1000, 0 })<<'\n';
	return 0;
}