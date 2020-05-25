#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, bool>> v;
int N;
int last;
int R[16][16];
int ret = 0;
bool isEnd = 0;

void dfs(int remainNum, int cnt)
{
	if (isEnd)
		return;
	if (v[last].second || remainNum == 1)
	{
		ret = max(ret, cnt);
		if (remainNum == 1)
			isEnd = 1;
		return;
	}

	if (remainNum % 2)
	{
		int temp = 0;
		int maxPoint = 0;
		for (int i = 0; i < N; i++)
		{
			if (v[i].second)
				continue;
			if (v[i].first > maxPoint)
			{
				temp = i;
				maxPoint = v[i].first;
			}
		}
		v[temp].second = 1;
		dfs(remainNum - 1, cnt);
		v[temp].second = 0;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (v[i].second || i == last)
				continue;
			for (int j = 0; j < N; j++)
				v[j].first += R[i][j];
			v[i].second = 1;
			dfs(remainNum - 1, cnt + 1);

			for (int j = 0; j < N; j++)
				v[j].first -= R[i][j];
			v[i].second = 0;
		}
	}
}


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		v.push_back({ a,0 });
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> R[i][j];
	cin >> last;

	dfs(N, 0);
	cout << ret;

	return 0;
}