#include<iostream>
#include<vector>
using namespace std;
vector<pair<pair<int, int>, int>> result;
int N, M;
string s[101];

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

void find(int i, int j)
{
	if (s[i][j] != '*')
		return;

	bool isPossible = true;
	int len = 1;
	while (1)
	{
		for (int k = 0; k < 4; k++)
		{
			int ny = i + len * dy[k];
			int nx = j + len * dx[k];
			if (!isRange(ny, nx) || s[ny][nx] == '.')
			{
				isPossible = false;
				break;
			}
		}
		if (!isPossible)
			break;
		++len;
	}
	if (len == 1)
		return;
	else
		result.push_back({ {i + 1, j + 1}, len - 1 });
}


int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> s[i];
	
	for (int i = 1; i < N-1; ++i)
		for (int j = 1; j < M-1; ++j)
			find(i,j);
	

	for (int i = 0; i < result.size(); ++i)
	{
		int row = result[i].first.first - 1;
		int col = result[i].first.second - 1;
		int len = result[i].second;

		s[row][col] = '.';
		for (int a = 1; a <= len; a++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ny = row + a * dy[k];
				int nx = col + a * dx[k];
				s[ny][nx] = '.';
			}
		}
	}
	bool isPossible = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (s[i][j] == '*')
			{
				isPossible = false;
				break;
			}
		}
		if (!isPossible)
			break;
	}

	if (isPossible)
	{
		cout << result.size()<<'\n';
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i].first.first << ' '
				<< result[i].first.second << ' '
				<< result[i].second << '\n';
		}
	}
	else
		cout << -1;
	
	
	return 0;
}