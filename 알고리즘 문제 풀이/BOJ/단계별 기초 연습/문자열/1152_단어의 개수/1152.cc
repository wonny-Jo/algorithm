#include<iostream>
using namespace std;


int blankCount(char* str)
{
	int count = 0;
	for (int i = 0;; i++)
	{
		if (!str[i])
			break;
		if (str[i + 1] == ' '&&str[i] == ' ')
			continue;
		if (str[i+1]!=' '&&str[i+1]!=NULL&&str[i]==' ')
			++count;
	}
	if (str[0] == ' ')
		--count;
	return count;
}

int main()
{
	char* N=new char[1000000];
	cin.getline(N,1000000);
	cout << blankCount(N) + 1;
	return 0;
}
