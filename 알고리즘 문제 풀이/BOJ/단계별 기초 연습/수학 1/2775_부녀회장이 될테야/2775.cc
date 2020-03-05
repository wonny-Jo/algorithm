#include<iostream>
using namespace std;

int main()
{
	int T, k, n;
	cin >> T;
	while (T--)
	{
		cin >> k >> n;
		long long result = 1,temp1=k+n,temp2=1;
		for (int i = 1; i < n; i++)
		{
			result *= temp1;
			--temp1;
			temp2*=i;
		}
		cout << result / temp2 << endl;
	}

	return 0;
}