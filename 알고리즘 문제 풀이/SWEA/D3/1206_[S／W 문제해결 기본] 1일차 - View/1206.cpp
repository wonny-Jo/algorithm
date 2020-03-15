#include<iostream>
using namespace std;

int main()
{
	int T = 10;
	for (int i = 1; i <= T; ++i)
	{
		int N;
		cin >> N;
		int num[1001];
		int sum = 0;
		for (int j = 0; j < N; ++j)
			cin >> num[j];
		int j = 2;
		int pivot;
		while (j < N)
		{
			int max = 0;
			pivot = j;
			for (int k = 1; k <= 2; ++k)
			{
				if (num[j] <= num[j + k])
				{
					j += k; break;
				}
				else if (num[j] <= num[j - k])
				{
					++j; break;
				}
				else if (max < num[j - k] || max < num[j + k])
					max = (num[j - k] > num[j + k]) ? num[j - k] : num[j + k];
			}
			if (pivot == j)
			{
				sum += num[j] - max;
				++j;
			}
		}
		cout << '#' << i << ' ' << sum << endl;
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}