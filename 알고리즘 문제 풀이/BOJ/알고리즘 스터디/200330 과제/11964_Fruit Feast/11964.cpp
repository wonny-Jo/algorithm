#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int T, A, B; cin >> T >> A >> B;
	int max = 0;
	int i = T / A;
	while (i >= 0)
	{
		int j = (T - (A * i)) / B;
		while (j >= 0)
		{
			int temp = (i * A + j * B) / 2;
			int temp2 = T - temp;//반하고 남는값	
			int k = temp2 / A;
			while (k>=0)
			{
				int l= (temp2 - (A * k)) / B;
				while (l >= 0)
				{
					int num = temp + A * k + B * l;
					if (max < num)
						max = num;
					if (max == T)
					{
						cout << max;
						return 0;
					}
					--l;
				}
				--k;
			}
			--j;
		}
		--i;
	}
	cout << max;
	return 0;
}