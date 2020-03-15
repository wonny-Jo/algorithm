#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		char str[100];
		cin >> str;
		int start_pos = 0;
		int end_pos;
		int len = strlen(str);
		bool isFind = true;
		for (int j = 1; j < len; ++j)
		{
			if (str[start_pos] == str[j])
			{
				end_pos = j;
				for (int k = 0; k < end_pos - start_pos; ++k)
				{
					if (str[start_pos + k] != str[end_pos + k])
					{
						isFind = false;
						break;
					}
					else
						isFind = true;
				}
				if (isFind == true)
				{
					cout << '#' << i + 1 << ' ' << end_pos << endl;
					break;
				}
			}
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}