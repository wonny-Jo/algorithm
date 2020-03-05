#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int S[101];
int n;
int pSum[101], pSqSum[101];

void precalc()
{
	sort(S, S + n);
	pSum[0] = S[0];
	pSqSum[0] = S[0] * S[0];
	for (int i = 1; i < n; ++i)
	{
		pSum[i] = pSum[i - 1] + S[i];
		pSqSum[i] = pSqSum[i - 1] + S[i] * S[i];
	}
}

int minError(int low, int high)
{
	int sum = pSum[high] - (low == 0 ? 0 : pSum[low - 1]);
	int sqSum = pSqSum[high] - (low == 0 ? 0 : pSqSum[low - 1]);

	int m = int(0.5 + (double)sum / (high - low + 1));
	int ret = sqSum - 2 * m * sum + m * m * (high - low + 1);
	return ret;
}

int cache[101][101];
int quantize(int from, int parts)
{
	if (from == n) return 0;
	if (parts == 0) return INF;
	int& ret = cache[from][parts];
	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = 1; from+i <= n; ++i)
	{
		ret = min(ret, minError(from, from + i - 1) + quantize(from + i, parts - 1));
	}
	return ret;
}


int main()
{
	int C;
	cin >> C;
	int s;
	for (int i = 0; i < C; ++i)
	{
		memset(cache, -1, sizeof(cache));
		cin >> n >> s;
		for (int j = 0; j < n; ++j)
			cin >> S[j];
		precalc();
		cout << quantize(0, s) << endl;;
	}
	

	return 0;
}