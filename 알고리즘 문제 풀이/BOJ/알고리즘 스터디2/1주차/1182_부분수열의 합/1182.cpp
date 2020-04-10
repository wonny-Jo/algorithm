#include<iostream>
#include<vector>
using namespace std;
int N, S;
int arr[21];
vector<int> v;
int cnt = 0;

bool check()
{
	int ret = 0;
	for (int i = 0; i < v.size(); ++i)
		ret += v[i];
	
	if (ret == S)
		return true;
	return false;
}

int dfs(int num)
{
	if (num == N)
		return 0;

	for (int i = num; i < N; ++i)
	{
		v.push_back(arr[i]);
		if (check())
			++cnt;
		dfs(i + 1);
		v.pop_back();
	}
	return cnt;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	
	cout << dfs(0);

	return 0;
}