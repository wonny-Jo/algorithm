#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	int N, K;
	int arr[10001];
	for (int i = 1; i <= T; i++)
	{
		cin >> N >> K;
		for (int j = 0; j < N; j++)
			cin >> arr[j];
		vector<int> v;
		v.push_back(arr[0]);
		for (int j = 1; j < N; j++)
		{
			if (v[v.size() - 1] < arr[j])
				v.push_back(arr[j]);
			else
			{
				int idx = lower_bound(v.begin(), v.end(), arr[j]) - v.begin();
				v[idx] = arr[j];
			}
		}
		cout << "Case #" << i << '\n';
		cout << (v.size() >= K) << '\n';
	}

	return 0;
}