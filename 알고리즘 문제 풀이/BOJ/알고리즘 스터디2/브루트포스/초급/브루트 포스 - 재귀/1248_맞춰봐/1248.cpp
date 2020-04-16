#include<iostream>
using namespace std;
int N;
char arr[11][11];
int result[11];
int sum[11][11] = { 0 };
bool isEnd = false;


void print()
{
	for (int i = 0; i < N; ++i)
		cout << result[i]<<' ';
	cout << endl;
}

bool check(int cnt)
{
	for (int i = 0; i <= cnt; ++i)
	{
		int sum = 0;
		for (int j = i; j <= cnt; ++j)
		{
			sum += result[j];
			if ((sum > 0 && arr[i][j] == '+') ||
				(sum < 0 && arr[i][j] == '-') ||
				(sum == 0 && arr[i][j] == '0'))
				continue;
			return false;
		}
	}
	return true;
}

void dfs(int cnt)
{
	if (isEnd)
		return;

	if (cnt == N)
	{
		print();
		isEnd = true;
		return;
	}

	for (int i = -10; i <= 10; i++)
	{
		result[cnt] = i;
		if (check(cnt))
			dfs(cnt + 1);
	}
}




int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = i; j < N; ++j)
			arr[i][j] = s[cnt++];

	dfs(0);
	
	return 0;
}