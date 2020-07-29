//2060kb, 0ms
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[10001];
int maxSum[10001];//각 자리까지 최대 양

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
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