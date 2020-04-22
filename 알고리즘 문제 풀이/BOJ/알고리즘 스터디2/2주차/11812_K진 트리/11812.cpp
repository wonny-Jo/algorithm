#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	long long N, K, Q; cin >> N >> K >> Q;
	for (int i = 0; i < Q; i++)
	{
		long long a, b; cin >> a >> b;
		
		if (K == 1)
			cout << abs(a - b)<<'\n';
		else 
		{
			long long cnt = 0;
			while (a != b)
			{
				if (a > b)
					a = (a + K - 2) / K;
				else
					b = (b + K - 2) / K;
				++cnt;
			}
			cout << cnt << '\n';
		}
	}

	return 0;
}