#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> v[501];
int time[501];
int priority[501] = { 0 };
int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> time[i];
		int num;
		while (1)
		{
			cin >> num;
			if (num == -1)
				break;
			v[num].push_back(i);;
			++priority[i];
		}
	}

	int ret[501] = { 0 };
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (!priority[i])
		{
			q.push(i);
			ret[i] = time[i];
		}

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			ret[y] = max(ret[y], ret[x] + time[y]);
			--priority[y];
			if (!priority[y])
				q.push(y);
		}
	}
	for (int i = 1; i <= N; i++)
		cout << ret[i] << '\n';
	
	return 0;
}