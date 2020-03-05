#include<iostream>
#include<algorithm>
using namespace std;

bool checkSame(string pattern, string name)
{
	int pos = 0;
	while (pos < pattern.size() && pos < name.size() && (pattern[pos] == '?' || pattern[pos] == name[pos]))
		++pos;
	
	if (pos == pattern.size())
		return pos == name.size();

	if (pattern[pos] == '*')
	{
		for (int i = 0; i <= name.size()-pos; ++i)
		{
			if (checkSame(pattern.substr(pos + 1), name.substr(pos + i)))
				return true;
		}
	}
	return false;
}

void printSame(string pattern, string filename[51], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (checkSame(pattern, filename[i]))
			cout << filename[i] << endl;
	}
}

int main()
{
	int C;
	cin >> C;
	int n;
	for (int i = 0; i < C; ++i)
	{
		string pattern;
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