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
	char* input = new char[1000000];
	cin >> input;
	int alphaCount[26] = {};
	for (int i = 0;; ++i)
	{
		if (!input[i])
			break;
		++alphaCount[(input[i] - 1) % 32];
	}
	int max = 0,alphaPointer;

	for (int i = 0; i < 26; i++)
	{
		if (alphaCount[i]>max)
		{
			max = alphaCount[i];
			alphaPointer = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (i == alphaPointer)
			continue;
		if (max == alphaCount[i])
		{
			delete input;
			cout << '?';
			return 0;
		}
	}
	cout << (char)(alphaPointer + 65);
	delete input;
	return 0;
}
