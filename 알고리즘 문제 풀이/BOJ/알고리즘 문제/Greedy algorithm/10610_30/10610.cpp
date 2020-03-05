#include<iostream>
#include<algorithm>
using namespace std;

bool compare(char a, char b)
{
	return a > b;
}

int main()
{
	string s;
	cin >> s;

	bool hasZero = false;
	int size = s.size();
	int checkThree = 0;
	for (int i = 0; i < size; ++i)
	{
		int temp = s[i] - '0';
		if (temp==0)
			hasZero = true;
		checkThree += temp;
	}

	if (!hasZero || checkThree % 3)
	{
		cout << -1;
		return 0;
	}
	sort(s.begin(), s.end(), compare);
	cout << s;

	return 0;
}