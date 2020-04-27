#include<iostream>
using namespace std;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	string word = "wolf";
	int wordPos = 0, Wcnt = 0;
	string s; cin >> s;
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == word[wordPos])
			++num;
		else
		{
			if (wordPos == 0)
				Wcnt = num;
			else
				if (Wcnt != num)
				{
					cout << 0;
					return 0;
				}

			wordPos = (wordPos + 1) % 4;
			if (s[i] != word[wordPos] || num == 0)
			{
				cout << 0;
				return 0;
			}
			else
				num = 1;
		}
	}
	if (Wcnt != num||wordPos!=3)
	{
		cout << 0;
		return 0;
	}

	cout << 1;
	return 0;
}