#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N; cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i)
	{
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), compare);
	int result = 0, last = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i].first >= last)
		{
			last = v[i].second;
			++result;
		}
	}
	cout << result;

	return 0;
}