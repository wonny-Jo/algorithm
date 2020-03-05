#include <iostream>
using namespace std;
int n;
int portNum[40002];
bool c[40002] = { 0 };

int max(int a, int b)
{
	return a > b ? a : b;
}

int connect(int num, int rightMax)
{
	if (num > n)
		return 0;

	int ret = 0;
	for (int i = num; i <= n; ++i) 
	{
		if (portNum[i] <= rightMax)
			ret = max(ret,connect(i + 1, rightMax));
		else
			ret = max(ret,1+ connect(max(i,portNum[i]), portNum[i]));
	}
	return ret;
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> portNum[i];
	cout << connect(1, 0);

	return 0;
}