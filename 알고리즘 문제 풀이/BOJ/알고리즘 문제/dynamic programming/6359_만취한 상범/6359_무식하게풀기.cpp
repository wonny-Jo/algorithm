#include<iostream>
#include<string.h>
using namespace std;

bool isOpen[101];
int n;
void openOrClose(int a)
{
	for (int i = a; i <= n; i+=a)
		isOpen[i] = !isOpen[i];
}

int countOpenDoor()
{
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		openOrClose(i);
	
	for (int i = 1; i <= n; ++i)
	{
		if (isOpen[i])
			++cnt;
	}
	return cnt;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		memset(isOpen, 0, sizeof(isOpen));
		cout << countOpenDoor() << endl;
	}
	return 0;
}