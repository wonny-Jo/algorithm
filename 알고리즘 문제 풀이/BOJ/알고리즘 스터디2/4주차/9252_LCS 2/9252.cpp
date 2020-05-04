#include<iostream>
using namespace std;
int table[1001][1001] = { 0 };
string ret[1001][1001];
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	string s1, s2; cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
		for (int j = 0; j < s2.size(); j++)
		{
			if (s1[i] == s2[j]) //���� ���ٸ� ���� ���ڱ����� �ִ밪+1
			{
				table[i + 1][j + 1] = table[i][j] + 1;
				ret[i + 1][j + 1] = ret[i][j] + s1[i];
			}
			else //���� ���� �ʴٸ� ���� ���ڵ��� �ִ밪�� ������
			{
				if (table[i + 1][j] > table[i][j + 1])
				{
					table[i + 1][j + 1] = table[i + 1][j];
					ret[i + 1][j + 1] = ret[i + 1][j];
				}
				else
				{
					table[i + 1][j + 1] = table[i][j + 1];
					ret[i + 1][j + 1] = ret[i][j + 1];
				}
			}
		}
	cout << table[s1.size()][s2.size()] << '\n' << ret[s1.size()][s2.size()];
	return 0;
}
