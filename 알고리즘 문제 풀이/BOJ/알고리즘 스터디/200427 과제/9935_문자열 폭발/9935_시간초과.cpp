#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	string s; cin >> s;
	string bomb; cin >> bomb;
	int pos, size = bomb.size();
	while (!s.empty()&&(pos=s.find(bomb))!=-1)
	{
		string temp = "";
		for (int i = 0; i < pos; ++i)
			temp += s[i];
		for (int i = pos+size; i < s.size(); i++)
			temp += s[i];
		s = temp;
	}
	if (s.empty())
		cout << "FRULA";
	else
		cout << s;

	return 0;
}