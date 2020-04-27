#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int N, K;
string s[51];
int visit[36]; //K개 선택 //초기 -1, 문자가 있으면 0, 선택 1
long long ret = 0;

void print()
{
	string result = "";
	while (ret > 0)
	{
		int temp = ret % 36;
		if (0 <= temp && temp <= 9)
			result += '0' + temp;
		else
			result += 'A' + (temp - 10);
		ret /= 36;
	}
	reverse(result.begin(), result.end());
	cout << result;
}

long long calcNum()
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		long long num = 0;
		for (int j = 0; j < s[i].size(); j++)
		{
			if ('0' <= s[i][j] && s[i][j] <= '9')
			{
				num *= 36;
				if (visit[s[i][j] - '0'] == 1)
					num += 35;
				else
					num += s[i][j] - '0';
			}
			else if ('A' <= s[i][j] && s[i][j] <= 'Z')
			{
				num *= 36;
				if (visit[s[i][j] - 'A' + 10] == 1)
					num += 35;
				else
					num += s[i][j] - 'A' + 10;
			}
		}
		sum += num;
	}
	return sum;
}

void dfs(int num, int cnt)
{
	if (cnt == K)
	{
		ret = max(ret, calcNum());
		return;
	}

	for (int i = num; i < 36; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			dfs(i + 1, cnt + 1);
			visit[i] = 0;
		}
	}

}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	memset(visit, -1, sizeof(visit));
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		for (int j = 0; j < s[i].size(); j++)
		{
			if ('0' <= s[i][j] && s[i][j] <= '9' && visit[s[i][j] - '0'] == -1)
			{
				visit[s[i][j] - '0'] = 0;
				++cnt;
			}
			else if ('A' <= s[i][j] && s[i][j] <= 'Z' && visit[s[i][j] - 'A' + 10] == -1)
			{
				visit[s[i][j] - 'A' + 10] = 0;
				++cnt;
			}
		}
	}
	cin >> K;
	if (K > cnt)
		K = cnt;

	dfs(0, 0);
	print();

	return 0;
}