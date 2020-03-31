#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> v1[100001];
vector<int> v2[100001];
bool visit1[100001] = { 0 };
bool visit2[100001] = { 0 };
int N, M, X;

int dfs(int start, vector<int> v[100001], bool visit[100001])
{
	stack<int> s;
	s.push(start);
	visit[start] = 1;
	int cnt = 1;
	while (!s.empty())
	{
		int x = s.top();
		s.pop();
		

		int size = v[x].size();
		for (int i = 0; i < size; ++i)
		{
			int y = v[x][i];
			if (!visit[y])
			{
				++cnt;
				visit[y] = 1;
				s.push(x);
				s.push(y);
				break;
			}
		}

	}
	return cnt;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	cin >> N >> M >> X;
	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		v1[a].push_back(b);
		v2[b].push_back(a);
	}

	int lowerNum = dfs(X, v1, visit1);
	int upperNum = dfs(X, v2, visit2);

	cout << upperNum << ' ' << N - lowerNum + 1;

	return 0;
}