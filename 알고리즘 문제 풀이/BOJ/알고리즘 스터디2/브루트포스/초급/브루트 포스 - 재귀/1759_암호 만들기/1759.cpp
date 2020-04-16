#include<iostream>
#include<algorithm>
using namespace std;
string m = "aeiou";
char str[16], ans[16];
int L, C;
bool c[16] = { 0 };

void print()
{
	cout << ans << '\n';
}

bool check()
{
	int cnt = 0;
	for (int i = 0; i < L; i++)
	{
		if (m.find(ans[i]) != -1)
			++cnt;
	}
	if (1 <= cnt && cnt <= L - 2)
		return true;
	return false;
}

void dfs(int num, int cnt)
{
	if (cnt == L)
	{
		if(check())
			print();
		return;
	}

	for (int i = num; i < C; ++i)
	{
		ans[cnt] = str[i];
		dfs(i + 1, cnt + 1);
	}
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> L >> C;
	
	for (int i = 0; i < C; i++)
		cin >> str[i];
	sort(str, str + C);

	dfs(0,0);

	return 0;
}