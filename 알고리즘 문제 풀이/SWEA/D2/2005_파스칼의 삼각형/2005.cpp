#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int arr[10][10];
	arr[0][0] = 1; arr[1][0] = 1; arr[1][1] = 1;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		for (int j = 2; j < N; ++j)
		{
			arr[j][0] = 1;
			for (int k = 1; k < j; ++k)
				arr[j][k] = arr[j - 1][k - 1] + arr[j - 1][k];
			arr[j][j] = 1;
		}
		cout << '#' << i + 1 << endl;
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < j + 1; ++k)
			{
				cout << arr[j][k] << ' ';
			}
			cout << endl;
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}