//1984kb, 92ms
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int arr[21][21];
bool c[21] = { 0 };

int checkMin()
{
	int sumStart = 0, sumLink = 0;
	vector<int> start, link;
	for (int i = 0; i < N; ++i)
	{
		if (c[i])
		{
			if (!start.empty())
				for (int j = 0; j < start.size(); ++j)
					sumStart += arr[i][start[j]] + arr[start[j]][i];
			start.push_back(i);
		}
		else
		{
			if (!link.empty())
				for (int j = 0; j < link.size(); ++j)
					sumLink += arr[i][link[j]] + arr[link[j]][i];
			link.push_back(i);
		}
	}
	return abs(sumLink - sumStart);
}

int dfs(int num, int cnt)
{
	if (cnt == N / 2)
		return checkMin();

	int ret = 40001;
	for (int i = num; i < N; i++)
	{
		if (!c[i])
		{
			c[i] = 1;
			ret = min(ret, dfs(i + 1, cnt + 1));
			c[i] = 0;
		}
	}
	return ret;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];

	cout << dfs(0, 0);
	return 0;
}