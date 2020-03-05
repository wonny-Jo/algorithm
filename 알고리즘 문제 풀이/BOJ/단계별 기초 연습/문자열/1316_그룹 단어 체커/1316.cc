#include<iostream>
using namespace std;
int _strlen(char* str)
{
	int count = 0;
	for (int i = 0;str[i]; ++i)
		++count;
	return count;
}

int main()
{
	int N;
	cin >> N;
	char** word = new char*[N];
	int groupWordCount = 0;
	for (int i = 0; i < N; ++i)
	{
		word[i] = new char[100];
		cin >> word[i];
		int checkGroup[26] = {};
		int size = _strlen(word[i]);
		for (int j = 0; j < size; ++j)
		{
			if (checkGroup[word[i][j] - 97] == 0)
				checkGroup[word[i][j] - 97] = 1;
			else if (checkGroup[word[i][j] - 97] == 1 && word[i][j] != word[i][j - 1])
			{
				--groupWordCount;
				break;
			}
		}
		++groupWordCount;
	}
	cout << groupWordCount;
	for (int i = 0; i < N; ++i)
		delete word[i];
	delete word;
	return 0;
}
