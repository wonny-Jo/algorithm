#include<iostream>
using namespace std;
int n;
bool one;

bool check(string s)
{
	int len = s.size();
	for (int size = 1; size < len; size++)
	{
		for (int start = 0; start < len-size; start++)
		{
			string a = s.substr(start, size);
			string b = s.substr(start + size, size);
			if (!a.compare(b))
				return false;
		}
	}
	return true;
}

void dfs(int len, string s) 
{
	if (!check(s) || one)
		return;
	if (len == n) 
	{
		cout << s << endl;
		one = 1;
		return;
	}

	dfs(len + 1, s + "1");
	dfs(len + 1, s + "2");
	dfs(len + 1, s + "3");
}

int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> n;
	dfs(0, "");
	return 0;
}

