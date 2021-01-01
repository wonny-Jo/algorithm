#include <iostream>

//////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> connected[201];

int solution(int n, vector<vector<int>> computers) 
{
	int answer = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j&&computers[i][j]==1)
				connected[i].push_back(j);

	bool visited[201] = { 0 };
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			++answer;

			//bfs
			queue<int> q;
			q.push(i);
			visited[i] = 1;

			while (!q.empty())
			{
				int x = q.front();
				q.pop();
				for (int j = 0; j < connected[x].size(); j++)
				{
					int y = connected[x][j];
					if (!visited[y])
					{
						visited[y] = 1;
						q.push(y);
					}
				}
			}
			//end bfs
		}
	}

	return answer;
}

//////////////////////////////////////////////////////////


int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n = 3;
	vector<vector<int>> computers = { {1,1,0},{1,1,0},{0,0,1} };
	cout << solution(n, computers) << '\n';
	return 0;
}