#include<iostream>
#include<algorithm>
using namespace std;

int cache[101][101];

string pattern, name;

bool checkSame(int pattern_pos, int name_pos)
{
	int& ret = cache[pattern_pos][name_pos];
	if (ret != -1)
		return ret;

	while (pattern_pos < pattern.size() &&
		name_pos < name.size() &&
		(pattern[pattern_pos] == '?' || pattern[pattern_pos] == name[name_pos]))
		return ret = checkSame(pattern_pos + 1, name_pos + 1);

	if (pattern_pos == pattern.size())
		return ret = (name_pos == name.size());

	if (pattern[pattern_pos] == '*')
	{
		if (checkSame(pattern_pos + 1, name_pos) || (name_pos < name.size() && checkSame(pattern_pos, name_pos + 1)))
			return ret = 1;
	}
	return ret = 0;
}

void printSame(string pattern, string filename[51], int n)
{
	for (int i = 0; i < n; ++i)
	{
		memset(cache, -1, sizeof(cache));
		name = filename[i];
		if (checkSame(0,0))
			cout << name << endl;
	}
}

int main()
{
	int C;
	cin >> C;
	int n;
	for (int i = 0; i < C; ++i)
	{
		cin >> pattern;
		cin >> n;
		string filename[51];
		for (int j = 0; j < n; ++j)
			cin>>filename[j];
		sort(filename, filename + n);
		printSame(pattern, filename, n);
	}

	return 0;
}