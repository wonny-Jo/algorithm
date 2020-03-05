#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int K;
	for (int i = 1; i <= T; ++i)
	{
		cin >> K;
		int j = 1;
		while (1)
		{
			if (j * (j + 1) / 2 >= K)
			{
				--j; break;
			}
			++j;
		}
		int data[50] = { 0 };
		for (int k = 1; k <= j;++k)
			data[k] = k * (k + 1) / 2;
		bool isTrue = false;
		for (int a = j; a > 0; --a)
		{
			for (int b = a; b > 0; --b)
			{
				for (int c = b; c > 0; --c)
				{
					if (data[a] + data[b] + data[c] == K)
					{
						isTrue = true;
					}
				}
			}
		}
		cout << isTrue << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}