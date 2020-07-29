//5020kb, 44ms
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<string, int> p1, pair<string, int> p2)
{
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<pair<string, int>> v;
	string s;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		v.push_back({ s,s.size() });
	}
	sort(v.begin(), v.end(), compare);

	vector<pair<string, int>>::iterator iter = v.begin();

	int size = v.size();
	cout << iter[0].first << "\n";
	for (int i = 1; i < size; ++i)
		if (iter[i].first != iter[i - 1].first)
			cout << iter[i].first << "\n";

	return 0;
}