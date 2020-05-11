#include<iostream>
#include<algorithm>
using namespace std;
int table[101][101][101] = { 0 };

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	for (int i = 0; i < s1.size(); i++)
		for (int j = 0; j < s2.size(); j++)
			for (int k = 0; k < s3.size(); k++)
			{
				if (s1[i] == s2[j] && s2[j] == s3[k])
					table[i + 1][j + 1][k + 1] = table[i][j][k] + 1;
				else
				{
					table[i + 1][j + 1][k + 1] = max(table[i+1][j+1][k],table[i+1][j][k+1]);
					table[i + 1][j + 1][k + 1] = max(table[i + 1][j + 1][k + 1], table[i][j + 1][k + 1]);
				}
			}
	cout << table[s1.size()][s2.size()][s3.size()];
	return 0;
}
