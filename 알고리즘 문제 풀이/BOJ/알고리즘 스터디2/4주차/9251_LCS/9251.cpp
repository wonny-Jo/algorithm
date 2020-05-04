#include<iostream>
#include<algorithm>
using namespace std;
int table[1001][1001] = { 0 };

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	string s1, s2; cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j]) //지금 같다면 이전 문자까지의 최대값+1
				table[i + 1][j + 1] = table[i][j] + 1;
			else //지금 같지 않다면 이전 문자들중 최대값을 가져옴
				table[i + 1][j + 1] = max(table[i + 1][j],table[i][j+1]);
		}
	cout << table[s1.size()][s2.size()];
	return 0;
}
