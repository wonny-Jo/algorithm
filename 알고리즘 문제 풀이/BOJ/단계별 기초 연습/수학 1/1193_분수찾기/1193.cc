#include<iostream>
using namespace std;

//int _strlen(char* str)
//{
//	int count = 0;
//	for (int i = 0; str[i]; ++i)
//		++count;
//	return count;
//}

int main()
{
	int input;
	cin >> input;
	int k = 0;
	for (int i = 1;; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			++k;
			if (k == input)
			{
				if (i%2==0)
				{
					cout << i - j + 1 << '/' << j;
				}
				else
					cout << j << '/' << i - j + 1;
				return 0;
			}
		}
	}

	return 0;
}
