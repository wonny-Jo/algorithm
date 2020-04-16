#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> v;
int arr[9];
bool visit[9] = { 0 };

void print()
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
	cout << '\n';
}

void dfs(int num, int cnt)
{
	if (cnt == M)
	{
		print();
		return;
	}

	for (int i = num; i < N; ++i)
	{
			v.push_back(arr[i]);
			dfs(i+1, cnt + 1);
			v.pop_back();
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
	
	return 0;
}