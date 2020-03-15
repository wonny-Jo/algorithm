#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		char str[20];
		cin >> str;
		int length = strlen(str);
		bool isPalindrome = true;
		cout << '#' << i + 1 << ' ';
		for (int j = 0; j < length / 2; ++j)
		{
			if (str[j] != str[length - 1 - j])
			{
				isPalindrome = false;
				break;
			}
		}
		cout << isPalindrome << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}