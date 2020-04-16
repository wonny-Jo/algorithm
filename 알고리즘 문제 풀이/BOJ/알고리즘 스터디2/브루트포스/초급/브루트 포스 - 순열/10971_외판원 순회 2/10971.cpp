#include<iostream>
#include<algorithm>
using namespace std;
int N;
int W[11][11];
int order[11];

int calcMinNum()
{
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (W[order[i]][order[i + 1]])
			sum += W[order[i]][order[i + 1]];
		else
			return 10000000;
	}
	return sum;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		order[i] = i;
		for (int j = 0; j < N; ++j)
			cin >> W[i][j];
	}
	order[N] = 0;
	int result = calcMinNum();
	while (next_permutation(order, order + N))
	{
		if (order[0] != 0)
			break;
		result = min(result, calcMinNum());
	}
	cout << result;
	return 0;
}