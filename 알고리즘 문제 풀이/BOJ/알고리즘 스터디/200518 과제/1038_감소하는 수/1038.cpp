#include<iostream>
using namespace std;

//arr[자릿수][최고자리의 수] //자릿수 1~10, 최고자리의 수 1~9
//arr[자릿수][최고자리의 수]=arr[자릿수][최고자리의 수-1]+arr[자릿수-1][최고자리의수-1]

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int arr[11][10] = { 0 };
	for (int i = 0; i < 10; ++i)
		arr[1][i] = 1;
	for (int i = 2; i <= 10; ++i)
		for (int j = i - 1; j < 10; ++j)
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];

	int sum[11][10] = { 0 };
	for (int i = 1; i <= 10; ++i)
	{
		sum[i][i - 1] = sum[i - 1][9] + arr[i][i - 1];
		for (int j = i; j < 10; ++j)
			sum[i][j] = sum[i][j - 1] + arr[i][j];
	}
	//sum[10][9]는 1023이 나온다.
	int N; cin >> N;
	N += 1;
	if (N > sum[10][9])
	{
		cout << -1;
		return 0;
	}

	int k = 9;
	while (N > 0)
	{
		for (int i = 1; i <= 10; ++i)
		{
			bool isChanged = false;
			for (int j = 0; j <= k; ++j)
			{
				if (N <= sum[i][j])
				{
					N -= sum[i][j] - sum[i - 1][j - 1];
					cout << j;
					k = j - 1;
					isChanged = true;
					break;
				}
			}
			if (isChanged)
				break;
		}
	}
}
