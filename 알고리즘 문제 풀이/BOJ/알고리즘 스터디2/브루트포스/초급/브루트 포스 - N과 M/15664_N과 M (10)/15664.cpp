#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<vector<int>> result;
vector<int> v;
int arr[9];

void print()
{
	sort(result.begin(), result.end());

	for (int i = 0; i < result[0].size(); i++)
		cout << result[0][i] << ' ';
	cout << '\n';
	for (int i = 1; i < result.size(); ++i)
		if (result[i] != result[i - 1])
		{
			for (int j = 0; j < result[i].size(); ++j)
				cout << result[i][j] << ' ';
			cout << '\n';
		}
}

void dfs(int num, int cnt)
{
	if (cnt == M)
	{
		result.push_back(v);
		return;
	}

	for (int i = num; i < N; ++i)
	{
		if (v.empty() || v[v.size() - 1] <= arr[i])
		{
			v.push_back(arr[i]);
			dfs(i+1,cnt + 1);
			v.pop_back();
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	dfs(0,0);
	print();
	return 0;
}