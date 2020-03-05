#include <iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
vector<int> v[51];
int mask[51] = { -1 };


//start가 있으면 점수를 반환하는 함수 //bfs로 하면 쉬울듯
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	mask[start] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		int size = v[x].size();
		for (int i = 0; i < size; ++i)
		{
			int y = v[x][i];
			if (mask[y]==-1)
			{
				q.push(y);
				mask[y] = mask[x]+1;
			}
		}
	}
}

int calcPoint()
{
	int max = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (mask[i] == -1)
			return -1;
		if (max < mask[i])
			max = mask[i];
	}
	return max;
}

void print(vector<pair<int, int>> v, int cnt)
{
	cout <<v[0].first<<' '<< cnt << endl;
	for (int i = 0; i < cnt; ++i)
		cout<<v[i].second<<' ';
	cout << endl;
}

//모든 후보를 스타트로 하여 점수를 저장해두는 함수
void calcfriendsPoint()
{
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; ++i)
	{
		memset(mask, -1, sizeof(mask));
		bfs(i);
		v.push_back({ calcPoint(),i });
	}
	sort(v.begin(), v.end());
	int cnt = 1;
	int min = v[0].first;
	while (min == v[cnt].first)
		++cnt;
	print(v, cnt);
}



int main()
{
	cin >> n;
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a == -1 || b == -1)
			break;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	calcfriendsPoint();
	
	return 0;
}