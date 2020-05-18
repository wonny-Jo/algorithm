#include <iostream>
#include<algorithm>
using namespace std;
int max_sum[2][3] = { 0 }, min_sum[2][3] = { 0 };

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int num[3];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> num[j];
		max_sum[1][0] = max(max_sum[0][0], max_sum[0][1]) + num[0];
		max_sum[1][1] = max(max(max_sum[0][0], max_sum[0][1]),max_sum[0][2]) + num[1];
		max_sum[1][2] = max(max_sum[0][1], max_sum[0][2]) + num[2];
		min_sum[1][0] = min(min_sum[0][0], min_sum[0][1]) + num[0];
		min_sum[1][1] = min(min(min_sum[0][0], min_sum[0][1]), min_sum[0][2]) + num[1];
		min_sum[1][2] = min(min_sum[0][1], min_sum[0][2]) + num[2];
		for (int j = 0; j < 3; j++)
		{
			max_sum[0][j] = max_sum[1][j];
			min_sum[0][j] = min_sum[1][j];
		}
	}

	cout << max(max(max_sum[1][0], max_sum[1][1]), max_sum[1][2])
		<< ' ' << min(min(min_sum[1][0], min_sum[1][1]), min_sum[1][2]);

	return 0;
}
