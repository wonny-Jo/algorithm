#include<iostream>
#include<vector>
#include<string>
using namespace std;
int k;
char s[11];
bool Used[11] = { 0 };
vector<string> result;

void dfs(int cnt, string num)
{
	if (cnt == k + 1)
	{
		result.push_back(num);
		return;
	}

	for (int j = 0; j <= 9; ++j)
		if (!Used[j])
			if ((s[cnt - 1] == '<' && num[cnt - 1] - '0' < j) ||
				(s[cnt - 1] == '>' && num[cnt - 1] - '0' > j))
			{
				Used[j] = 1;
				dfs(cnt + 1,num+to_string(j));
				Used[j] = 0;
			}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> s[i];

	for (int i = 0; i < 10; i++)
	{
		Used[i] = 1;
		string str;
		str+='0' + i;
		dfs(1,str);
		Used[i] = 0;
	}

	cout << result[result.size() - 1] << endl << result[0];
	
	return 0;
}