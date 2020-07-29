//1984kb, 0ms
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int A[12];
int maxResult = -1000000000;
int minResult = 1000000000;

void operation(int num, int plus_count, int minus_count, int multi_count, int div_count, int sum)
{
	if (num == N)
	{
		maxResult = max(maxResult, sum);
		minResult = min(minResult, sum);
	}

	if (plus_count>0)
		operation(num + 1, plus_count - 1, minus_count, multi_count, div_count, sum + A[num]);
	if (minus_count>0)
		operation(num + 1, plus_count, minus_count - 1, multi_count, div_count, sum - A[num]);
	if (multi_count>0)
		operation(num + 1, plus_count, minus_count, multi_count - 1, div_count, sum * A[num]);
	if (div_count>0)
		operation(num + 1, plus_count, minus_count, multi_count, div_count - 1, sum / A[num]);

}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	int count[4];
	for (int i = 0; i < 4; ++i)
		cin >> count[i];

	operation(1, count[0], count[1], count[2], count[3], A[0]);
	cout << maxResult << '\n' << minResult;
	return 0;
}