#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int num=0;
	int result = 0;
	int size = s.size();
	bool isMinus = false;
	for (int i = 0; i < size; ++i)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			if (!isMinus)
				result += num;
			else
				result -= num;
			num = 0;
			if (s[i] == '-')
				isMinus = true;
		}
		else
		{
			num *= 10;
			num += s[i] - '0';	
		}
	}
	if (!isMinus)
		result += num;
	else
		result -= num;
	cout << result << endl;

	return 0;
}