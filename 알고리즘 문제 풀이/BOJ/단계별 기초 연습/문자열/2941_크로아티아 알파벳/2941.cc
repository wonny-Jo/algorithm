#include<iostream>
using namespace std;

int main()
{
	char string[200];
	cin >> string;
	int count=0,i = 0;
	while(string[i])
	{
		char temp = string[i];
		if (temp == 'c')
		{
			if (string[i + 1] == '=' || string[i + 1] == '-')
				++i;
		}
		else if (temp == 'd')
		{
			if (string[i + 1] == 'z'&&string[i + 2] == '=')
				i += 2;
			else if (string[i + 1] == '-')
				++i;
		}
		else if (temp == 'l')
		{
			if (string[i + 1] == 'j')
				++i;
		}
		else if (temp == 'n')
		{
			if (string[i + 1] == 'j')
				++i;
		}
		else if (temp == 's')
		{
			if (string[i + 1] == '=')
				++i;
		}
		else if (temp == 'z')
		{
			if (string[i + 1] == '=')
				++i;
		}
		++i; 
		++count;
	}

	cout << count;
	return 0;
}