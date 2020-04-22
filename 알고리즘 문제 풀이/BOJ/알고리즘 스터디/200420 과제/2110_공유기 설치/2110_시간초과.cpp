#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
bool c[200001] = { 0 };
int N, C;
int x[200001];

int calcDist()
{
	int minDist = 200000;
	for (int i = 0; i < C-1; i++)
		minDist = min(minDist, v[i+1] - v[i]);
	return minDist;
}

int dfs(int num)
{
	if (v.size() == C)
		return calcDist();
	if (num == N)
		return -1;

	int ret = 0;
	for (int i = num; i < N; i++)
		if (!c[i])
		{
			c[i] = 1;
			v.push_back(x[i]);
			ret = max(ret, dfs(i + 1));
			c[i] = 0;
			v.pop_back();
		}
	return ret;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; ++i)
		cin >> x[i];
	sort(x, x + N);

	cout << dfs(0);

	return 0;
}