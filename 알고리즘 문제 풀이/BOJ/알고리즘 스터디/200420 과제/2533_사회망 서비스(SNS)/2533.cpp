#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
vector<int> v[1000001]; //Ʈ�� ����
bool visit[1000001] = { 0 }; //�湮

int dp[1000001][2];

int dfs(int num, bool early)
{
	int &ret=dp[num][early];
	if (ret != -1)
		return ret;

	if (early) //���� ���� �󸮾���͸� ������ �󸮾���Ϳ����ǰ� �ƴϾ �ȴ�.
	{
		ret = 1;
		for (int i = 0; i < v[num].size(); i++)
		{
			int x = v[num][i];
			if (!visit[x])
			{
				visit[x] = 1;
				ret += min(dfs(x, 1), dfs(x, 0));
				visit[x] = 0;
			}
		}
	}
	else //���� �󸮾���Ͱ� �ƴϸ� ���� ����Ǿ� �ִ� ����� �� �󸮾���Ϳ����Ѵ�.
	{
		ret = 0;
		for (int i = 0; i < v[num].size(); i++)
		{
			int x = v[num][i];
			if(!visit[x])
			{
				visit[x] = 1;
				ret += dfs(x, 1);
				visit[x] = 0;
			}
		}
	}
	return ret;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	memset(visit, 0, sizeof(visit));
	visit[1] = 1;
	int num1 = dfs(1, 0); //ó�� ������ �󸮾���Ͱ� �ƴѰ��

	memset(visit, 0, sizeof(visit));
	visit[1] = 1;
	int num2 = dfs(1, 1); //ó�� ������ �󸮾������ ���

	cout << min(num1, num2);

	return 0;
}