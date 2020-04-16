#include <iostream>
using namespace std;


int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int nNum = 10, nStr = 26;

	string s; cin >> s;
	int ret = (s[0] == 'c') ? nStr : nNum;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == 'c')
		{
			if (s[i] == s[i - 1])
				ret*=nStr-1;
			else
				ret *= nStr;
		}
		else
		{
			if (s[i] == s[i - 1])
				ret*=nNum-1;
			else
				ret *= nNum;
		}
	}
	cout << ret;
	return 0;
}