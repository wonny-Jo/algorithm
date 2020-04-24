#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
string board[26];
vector<int> result;
int direct[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int N;

bool isRange(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;
	return true;
}


void bfs(int y, int x)
{
	board[y][x] = '0';
	queue<pair<int, int>> q;
	int cnt = 0;
	q.push({ y,x });

	while (!q.empty())
	{
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();
		++cnt;
		for (int i = 0; i < 4; i++)
		{
			int newY = ny + direct[i][0];
			int newX = nx + direct[i][1];
			if (isRange(newY, newX) && board[newY][newX] == '1')
			{
				board[newY][newX] = '0';
				q.push({ newY,newX });
			}
		}
	}
	result.push_back(cnt);
}


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == '1')
				bfs(i, j);
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';


	return 0;
}