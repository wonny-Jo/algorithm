#include<iostream>
#include<vector>
using namespace std;
int n;
int dist[11][11] = { 0 };

int shortestPath(vector<int>& path, vector<bool>& visited, int currentLength)
{
	if (path.size() == n)
		return currentLength + dist[0][path.back()];
	int ret = INT32_MAX;

	for (int i = 0; i < n; ++i)
	{
		if (visited[i]) continue;
		int here = path.back();
		path.push_back(i);
		visited[i] = true;
		int cand = shortestPath(path, visited, currentLength + dist[here][i]);
		ret = (ret < cand) ? ret : cand;
		visited[i] = false;
		path.pop_back();
	}
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			cin >> dist[i][j];
			dist[j][i] = dist[i][j];
		}
	}
	vector<int> path;
	path.push_back(0);
	vector<bool> visited(n,0);
	visited[0] = true;
	int currentLength = 0;
	cout << shortestPath(path,visited,currentLength) << endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}