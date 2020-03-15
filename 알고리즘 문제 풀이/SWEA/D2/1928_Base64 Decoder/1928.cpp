#include<iostream>
#include<string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	string encString;
	long num;
	string decString;
	int transInt;
	int count;
	for (int i = 0; i < T; i++)
	{
		cin >> encString;
		count = 0;
		cout << "#" << i + 1 << " ";
		while (4 * count < encString.length())
		{
			num = 0;
			for (int j = 4 * count; j < 4 * count + 4; j++)
			{
				transInt = (int)encString[j];
				if (transInt >= 65 && transInt <= 90)
					num += transInt - 65;
				else if (transInt >= 97 && transInt <= 122)
					num += transInt - 71;
				else
					num += transInt + 4;
				num *= 64;
			}
			num /= 64;
			for (int j = 2; j >= 0; j--)
			{
				decString[j] = (char)(num % 256);
				num /= 256;
			}
			for (int j = 0; j < 3; j++)
				cout << decString[j];
			++count;
		}
		cout << endl;
	}



	return 0;
}