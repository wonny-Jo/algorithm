#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		int num[100001];
		for (int j = 0; j < N; ++j)
			cin >> num[j];
		int max = -1000;
		int sum = 0;
		for (int j = 0; j < N; ++j)
		{
			sum += num[j];
			if (max < sum)
				max = sum;
			if (sum < 0)
				sum = 0;
		}
		cout << '#' << i + 1 << ' ' << max << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}