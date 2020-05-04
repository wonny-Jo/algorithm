#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	long long T, N; cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		long long coin = 2500000000000000;	//25*10^14
		int ret = 0;
		while (N != 0)
		{
			//한번에 100단위씩 언제가 최소가 되는지 구하면 된다.
			//왜냐하면 100단위씩 서로 독립적으로 결정되기 때문.
			long long minRet = 100;
			long long nextN;
			long long num25, num10, num1;
			long long coin10, coin1; //ex)coin=2500, coin10=1000, coin1=100
			coin10 = coin * 4; coin10 /= 10; coin1 = coin10 / 10;
			num25 = N / coin;
			while (num25 >= 0)
			{
				long long temp = N - coin * num25;
				num10 = temp / coin10;
				while (num10 >= 0)
				{
					long long temp1 = temp - coin10 * num10;
					num1 = temp1 / coin1;
					temp1 -= coin1 * num1;
					if (minRet > num25 + num10 + num1)
					{
						minRet = num25 + num10 + num1;
						nextN = temp1;
					}
					--num10;
				}
				--num25;
			}
			ret += minRet;
			N = nextN;
			coin /= 100;
		}
		cout << ret << '\n';
	}

	return 0;
}
