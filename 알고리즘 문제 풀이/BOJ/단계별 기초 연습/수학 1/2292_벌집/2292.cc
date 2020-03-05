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
	if (input==1)
	{
		cout << "1";
		return 0;
	}
	int i = 1;
	input -= 1;
	while (true)
	{
		if (input <= 6 * i)
		{
			cout << i + 1;
			return 0;
		}
		input -= 6 * i;
		++i;
	}
	return 0;
}
