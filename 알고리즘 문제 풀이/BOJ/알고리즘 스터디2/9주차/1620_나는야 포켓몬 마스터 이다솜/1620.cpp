#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	int N, M; cin >> N >> M;
	map<string, string> char_sort;
	map<string, string> num_sort;
	for (int i = 1; i <= N; i++)
	{
		string s; cin >> s;
		string num = to_string(i);
		char_sort[s] = num;
		num_sort[num] = s;
	}

	for (int i = 0; i < M; i++)
	{
		string s; cin >> s;
		if ('0' <= s[0] && s[0] <= '9')
			cout << num_sort[s] << '\n';
		else
			cout << char_sort[s] << '\n';
	}

	return 0;
}