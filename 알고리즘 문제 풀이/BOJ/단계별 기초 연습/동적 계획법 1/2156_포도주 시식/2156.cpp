#include<iostream>
using namespace std;
int N;
int arr[10001];
int maxSum[10001];//�� �ڸ����� �ִ� ��

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	maxSum[1] = arr[1];
	maxSum[2] = maxSum[1] + arr[2];
	for (int i = 3; i <= N; ++i)
		maxSum[i] = max(maxSum[i - 1], max(maxSum[i - 2] + arr[i], maxSum[i - 3] + arr[i - 1] + arr[i]));
	cout << maxSum[N];
	return 0;
}