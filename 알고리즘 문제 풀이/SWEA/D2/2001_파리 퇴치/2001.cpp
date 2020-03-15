#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int arr[15][15];
	for (int i = 0; i < T; ++i)
	{
		int N, M;
		cin >> N >> M;
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				cin >> arr[j][k];
		int sum, result = 0;
		for (int j = 0; j <= N - M; ++j)
			for (int k = 0; k <= N - M; ++k)
			{
				sum = 0;
				for (int a = 0; a < M; ++a)
					for (int b = 0; b < M; ++b)
						sum += arr[j + a][k + b];
				if (result < sum)
					result = sum;
			}
		cout << '#' << i + 1 << ' ' << result << endl;
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}