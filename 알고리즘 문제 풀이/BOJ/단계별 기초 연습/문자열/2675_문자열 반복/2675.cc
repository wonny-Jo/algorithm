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
	int T;
	cin >> T;
	char** result =new char*[T];
	for (int i = 0; i < T; i++)
	{
		int R;
		cin >> R;
		char* str = new char[20];
		cin >> str;
		int size = _strlen(str);
		result[i] = new char[size*R+1];
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < R; k++)
				result[i][R*j + k] = str[j];
			result[i][R*size] = NULL;
		}
		delete str;
	}
	for (int i = 0; i < T; i++)
	{
		cout << result[i] << endl;;
		delete result[i];
	}
	delete result;
	return 0;
}
