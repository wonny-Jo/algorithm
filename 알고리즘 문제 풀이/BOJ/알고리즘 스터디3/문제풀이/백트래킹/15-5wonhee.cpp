//1984kb, 4276ms
#include<iostream>
#include<string.h>
using namespace std;
int N;
int c[16];
int cnt = 0;

void dfs(int num)
{
	if (num == N)
		++cnt;

	for (int i = num; i < N; ++i) //i is row
	{
		for (int j = 0; j < N; ++j) //j is col
		{
			bool isPossible = true;
			for (int k = 0; k < i; ++k)
			{
				if (j == c[k] || i - k == abs(j - c[k]))
				{
					isPossible = false;
					break;
				}
			}
			if (isPossible)
			{
				c[i] = j;
				dfs(num + 1);
				c[i] = -1;
			}
		}
		if (c[i] == -1)
			return;
	}
}

void search()
{
	for (int i = 0; i < N; ++i)
	{
		memset(c, -1, sizeof(c));
		c[0] = i;
		dfs(1);
	}
	cout << cnt;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	search();
	return 0;
}