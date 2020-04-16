#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v;
int N;
bool c[16] = { 0 };

int dfs(int cnt,int sum)
{
	if (cnt == N)
		return sum;
	if (cnt > N)
		return 0;
	

	int ret = 0;

	ret = max(ret, dfs(cnt + v[cnt].first, sum + v[cnt].second));
	ret = max(ret, dfs(cnt + 1, sum));

	return ret;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	cout<<dfs(0,0);

	return 0;
}