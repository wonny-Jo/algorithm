#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		int num[2];
		cin >> num[0] >> num[1];
		cout << "Case #"<< i<< ": ";
		cout << num[0] + num[1] << endl;

	}


	return 0;
}

