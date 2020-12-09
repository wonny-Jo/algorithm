#include<iostream>
#include<algorithm>
using namespace std;
int N;
int arr[1001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	int sum = 0, ret = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
		ret += sum;
	}
	cout << ret;
	return 0;
}
