#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string s = "";
string result;
int N;
int first, last;
void dfs(int low, int high, string t)
{
	if (t.size()==80||low > high)
	{
		if (result.empty() || result > t)
		{
			result = t;
			first = low;
			last = high;
		}
		return;
	}

	if (s[low] < s[high])
	{
		t += s[low];
		dfs(low + 1, high, t);
	}
	else if (s[low] > s[high])
	{
		t += s[high];
		dfs(low, high - 1, t);
	}
	else
	{
		t += s[low];
		dfs(low + 1, high, t);
		t[t.size() - 1] = s[high];
		dfs(low, high - 1, t);
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char a; cin >> a;
		s += a;
	}

	first = 0; last = N - 1;
	while (first <= last)
	{
		string t = "";
		dfs(first, last, t);
		cout << result<<'\n';
		result.clear();
	}
	
	return 0;
}