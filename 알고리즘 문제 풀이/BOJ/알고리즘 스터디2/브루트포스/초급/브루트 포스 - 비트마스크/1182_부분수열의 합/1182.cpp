#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N, S; cin >> N >> S;
	int arr[21];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int ans = 0;
	for (int i = 1; i < (1<<N); i++)
	{
		int sum = 0;
		for (int k = 0; k < N; k++)
			if (i & (1 << k))
				sum += arr[k];
		if (sum == S)
			++ans;
	}
	cout << ans;


	return 0;
}