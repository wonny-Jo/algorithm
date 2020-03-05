#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = n; i > 1; i-=2)
	{
		cout << i << "\n";
		cout << i - 1 << "\n";
	}
	if (n % 2 == 1)
		cout << 1 << "\n";
	return 0;
}