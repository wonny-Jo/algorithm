#include<iostream>
#include<vector>
using namespace std;
int N;
bool adj[501][501] = { 0 }; //adj[a][b] // b보다 a가 순위가 높음
int indegree[501] = { 0 }, rank[501]; //indegree: 나보다 앞에 몇명 있는지, rank: 순위(index)에 따른 넘버

int main()
{
	cin.tie(0); cout.tie(0);
	cin.sync_with_stdio(0);
	int T; cin >> T;
	for (int a = 0; a < T; a++)
	{
		cin >> N;
				for (int i = 0; i < N; i++)
			cin >> rank[i];
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				adj[rank[i]][rank[j]] = true;
				indegree[rank[j]]++;
			}
		}

		int M; cin >> M;
		for (int i = 0; i < M; i++)
		{
			int num1, num2; cin >> num1 >> num2;
			//순위 바꾸기
			if (adj[num1][num2])
			{
				adj[num1][num2] = false;
				adj[num2][num1] = true;
				indegree[num2]--;
				indegree[num1]++;
			}
			else
			{
				adj[num2][num1] = false;
				adj[num1][num2] = true;
				indegree[num1]--;
				indegree[num2]++;
			}
		}

		int now = 0;
		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0)
			{
				now = i;
				break;
			}
		}

		vector<int> result;
		for (int i = 0; i < N; i++)
		{
			if (now == 0)
				break;

			result.push_back(now);
			int start = now;
			now = 0;
			for (int j = 1; j <= N; j++)
			{
				if (adj[start][j])
				{
					indegree[j]--;
					if (indegree[j] == 0)
						now = j;
				}
			}
		}

		if (result.size() == N)
		{
			for (int i = 0; i < N; i++)
				cout << result[i] << ' ';
			cout << '\n';
		}
		else
			cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}