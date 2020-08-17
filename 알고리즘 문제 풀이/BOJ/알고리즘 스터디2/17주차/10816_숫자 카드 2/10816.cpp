#include<iostream>
#include<algorithm>
using namespace std;
int arr[500001];
int N, M;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a; cin >> a;
		cout << (upper_bound(arr, arr + N, a) - arr) - (lower_bound(arr, arr + N, a) - arr) << ' ';
	}

	return 0;
}
