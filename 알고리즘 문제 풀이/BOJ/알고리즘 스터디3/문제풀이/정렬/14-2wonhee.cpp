//5892kb, 284ms
#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);

	cout << arr[0] << '\n';
	for (int i = 1; i < N; ++i)
	{
		if (arr[i - 1] != arr[i])
			cout << arr[i] << '\n';
	}
	return 0;
}