#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool learned[27] = { 0 };
int N, K;
int ret = 0;
vector<string> word;

int cntReadNum()
{
	int cnt = 0;
	for (int i = 0; i < word.size(); i++)
	{
		bool isRead = true;
		string w = word[i];
		for (int j = 4; j < w.size()-4; j++)
		{
			if (!learned[w[j] - 'a'])
			{
				isRead = false;
				break;
			}
		}
		if (isRead)
			++cnt;
	}
	return cnt;
}

void dfs(int num, int cnt)
{
	if (cnt == K)
	{
		ret = max(ret, cntReadNum());
		return;
	}

	for (int i = num; i < 26; i++)
	{
		if (!learned[i])
		{
			learned[i] = 1;
			dfs(i, cnt + 1);
			learned[i] = 0;
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> K;
	if (K < 5)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		string temp; cin >> temp;
		word.push_back(temp);
	}
	
	//anta tica -> a c i n t
	learned['a' - 'a'] = 1;
	learned['c' - 'a'] = 1;
	learned['i' - 'a'] = 1;
	learned['n' - 'a'] = 1;
	learned['t' - 'a'] = 1;
	K -= 5;

	dfs(0, 0);
	cout << ret;

	return 0;
}