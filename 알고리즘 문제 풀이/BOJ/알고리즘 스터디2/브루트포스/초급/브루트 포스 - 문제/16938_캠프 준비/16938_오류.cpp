#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
bool c[16] = { 0 };
int N, L, R, X;
int arr[16];
int cnt = 0;
vector<int> v;


bool isOk(int num)
{
	if (v.empty())
		return true;
	if (abs(v[0] - num) < X)
		return false;
	return true;
}

int dfs(int num,int sum)
{ 
	if (num == N && sum > R)
		return -1;
	if (v.size()>=2&&L <= sum && sum <= R)
		++cnt;

	for (int i = num; i < N; ++i)
	{
		if (!c[i]&&isOk(arr[i]))
		{
			v.push_back(arr[i]);
			c[i] = 1;
			dfs(i + 1, sum + arr[i]);
			c[i] = 0;
			v.pop_back();
		}
	} 
	return cnt;
}

int main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	cout<<dfs(0,0);

	return 0;
}
