//1984kb, 36ms
#include<iostream>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long N; cin >> N;
	long long i = 666, count = 0;
	long long temp = i;
	while (1)
	{
		if (temp % 1000 == 666)
		{
			++count;
			if (count == N)
			{
				cout << i;
				return 0;
			}
			temp = ++i;
			continue;
		}
		temp /= 10;
		if (!temp)
			temp = ++i;
	}

	return 0;
}