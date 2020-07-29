//3648kb, 48ms
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int x, y;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(), compare);

	for (vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << (*iter).first << ' ' << (*iter).second << "\n";


	return 0;
}