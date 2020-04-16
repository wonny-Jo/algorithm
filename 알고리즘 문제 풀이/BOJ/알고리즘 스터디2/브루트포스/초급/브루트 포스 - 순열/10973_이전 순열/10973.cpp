#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	int arr[10001];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	if (prev_permutation(arr, arr + N) == 0)
		cout << -1;
	else
	{
		for (int i = 0; i < N; i++)
			cout << arr[i]<<' ';
	}

	return 0;
}