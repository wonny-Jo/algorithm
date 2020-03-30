#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;


bool checkBG(vector<int> connect[20001], int c[20001],int num)
{
	queue<int> q;
	q.push(num); 
	c[num] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		int size = connect[x].size();
		for (int i = 0; i < size; ++i)
		{
			int y = connect[x][i];
			if (c[y]==-1)
			{
				c[y] = (c[x] + 1) % 2;
				q.push(y);
			}
			else
			{
				if (c[x] == c[y])
					return false;
			}
		}
	}
	return true;
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int K; cin >>K;
	int V, E;
	for (int i = 0; i < K; ++i)
	{
		vector<int> connect[20001];
		cin >> V >> E;
		for (int j = 0; j < E; ++j)
		{
			int a, b; cin >> a >> b;
			connect[a].push_back(b);
			connect[b].push_back(a);
		}
		int c[20001];
		memset(c, -1, sizeof(c));
		bool isTrue = false;
		for (int j = 1; j <= V; ++j)
		{
			if (c[j]==-1)
			{
				isTrue = checkBG(connect,c,j);
				if (!isTrue)
					break;
			}
		}
		if(!isTrue)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

	}

	return 0;
}