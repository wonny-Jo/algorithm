#include<iostream>
using namespace std;
int N;
int arr[10001];
int maxSum[10001][2];//0�� �ϳ������� �����°��, 1�� �ΰ������� �����°��

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	
	maxSum[0][0] = maxSum[0][1] = 0; 
	maxSum[1][0] = maxSum[1][1] = arr[1];
	for (int i = 2; i <= N; ++i)
	{
		maxSum[i][0] = maxSum[i - 1][1] + arr[i]; //0�� ���ӵǸ� �ȵǹǷ� �ϳ� �� ��ġ�� 1�� ���� ������
		maxSum[i][1] = max(maxSum[i - 2][0], maxSum[i - 2][1]) + arr[i]; //1�� �� �� ���� ������ ū ���� ������
	}

	int result = max(maxSum[N][0], maxSum[N][1]);
	result = max(result, maxSum[N - 1][0]);
	cout << result;
	return 0;
}