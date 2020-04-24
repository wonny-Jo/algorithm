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
	for (int i = 0; i < T; i++)
	{
		int N; cin >> N;
		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++)
		{
			int a, b; cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());

		int cnt = 0;
		int min = v[0].second;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].second > min)
				++cnt;
			else
				min = v[i].second;
		}
		cout << N-cnt<<'\n';
	}

	return 0;
}