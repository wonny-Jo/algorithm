#include<iostream>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;
int N;
int c[16];
int cnt = 0;

void bfs(int num)
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
				bfs(num + 1);
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
		bfs(1);
	}
	cout << cnt;
}

int main()
{
	cin >> N;
	search();
	return 0;
}