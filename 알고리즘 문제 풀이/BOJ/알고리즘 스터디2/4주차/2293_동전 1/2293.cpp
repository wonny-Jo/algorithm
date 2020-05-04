#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int arr[101];
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	//���� ���� �������� ä��� �ִ� ��쿡 üũ
	//�� ���� �������� ���� ������� ������ �͵��� �����ָ�ȴ�.
	int dp[10001] = { 0 };
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = arr[i]; j <= k; j++)
			dp[j] += dp[j - arr[i]];
	cout << dp[k] << '\n';

	return 0;
}
