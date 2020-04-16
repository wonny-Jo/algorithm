#include<iostream>
using namespace std;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int M, N, x, y; cin >> M >> N >> x >> y;
		int temp = x;
		bool isError = false;
		while(temp%M!=x%M||temp%N!=y%N)
		{
			temp += M;
			if (temp > M * N)
			{
				isError = true;
				break;
			}
		}
		if (isError)
			cout << -1 << endl;
		else
			cout << temp << endl;

	}

	return 0;
}