#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int arr[51] = { 0 };
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
		cin>>arr[i];
	sort(arr, arr + N);
	cout << arr[0] * arr[N - 1];
	return 0;
}