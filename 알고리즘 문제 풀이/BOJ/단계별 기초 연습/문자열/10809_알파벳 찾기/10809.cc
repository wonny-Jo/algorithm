#include<iostream>
using namespace std;

int _strlen(char* str)
{
	int count = 0;
	for (int i = 0;; i++)
	{
		if (!str[i])
			break;
		++count;
	}
	return count;
}

int main()
{
	char* str = new char[100];
	cin >> str;
	int firstPoint[26];
	for (int i = 0; i < 26; i++)
		firstPoint[i] = -1;
	int size = _strlen(str);
	for (int i = 0; i < size; ++i)
	{
		if (firstPoint[str[i] - 97] == -1)
			firstPoint[str[i] - 97] = i;
	}
	for (int i = 0; i < 26; ++i)
		cout << firstPoint[i] << " ";
	delete str;
	return 0;
}
