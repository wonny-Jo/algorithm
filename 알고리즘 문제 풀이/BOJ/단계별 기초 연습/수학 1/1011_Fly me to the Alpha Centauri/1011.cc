#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	long long x, y, dist;
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		dist = y - x;
		int twice = 0, index = 1, count = 0;
		while (dist > index)
		{
			dist -= index;
			if (twice == 1)
			{
				++index;
				twice = 0;
			}
			else
			{
				++twice;
			}
			++count;
		}
		++count;
		cout << count<<endl;

	}

	return 0;
}