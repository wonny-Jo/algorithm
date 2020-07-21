#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
bool visited[110];
int N, M;

int dfs(int num, vector<int> v[100])
{
	int ret = 1;
	visited[num] = true;
	int size = v[num].size();
	for (int i = 0; i <size; i++) 
	{
		int next = v[num][i];
		if (!visited[next])
			ret += dfs(next, v);
	}
	return ret;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int> light[100];
	vector<int> heavy[100];
	cin >> N >> M;
	for (int i = 0; i < M; i++) 
	{
		int a, b; cin >> a >> b;
		light[a].push_back(b);
		heavy[b].push_back(a);
	}
	int result = 0;
	for (int i = 1; i <= N; i++) 
	{

		memset(visited, 0, sizeof(visited));
		if (dfs(i, light) > (N + 1) / 2)
			result++;
		memset(visited, 0, sizeof(visited));
		if (dfs(i, heavy) > (N + 1) / 2)
			result++;
	}
	cout << result;
	return 0;
}