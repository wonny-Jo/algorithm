#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		cout << (int)pow(n, 0.5) << endl;
	}
	return 0;
}