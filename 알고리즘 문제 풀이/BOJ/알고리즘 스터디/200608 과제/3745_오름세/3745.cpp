#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[100001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	while (cin >> N)
	{
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		
		vector<int> v;
		v.push_back(arr[0]);
		for (int i = 1; i < N; i++)
		{
			if (v[v.size() - 1] < arr[i])
				v.push_back(arr[i]);
			else
			{
				int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
				v[idx] = arr[i];
			}
		}
		cout << v.size() << '\n';
	}

	return 0;
}