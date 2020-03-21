#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N; cin >> N;
	int i = 2;
	while (N != 1)
	{
		while (N % i == 0)
		{
			cout << i << endl;
			N /= i;
		}
		++i;
	}


	return 0;
}