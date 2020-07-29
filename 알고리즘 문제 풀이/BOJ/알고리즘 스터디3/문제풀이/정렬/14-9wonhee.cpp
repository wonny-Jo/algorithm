//9804kb, 80ms
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<pair<int, int>, string> p1, pair<pair<int, int>, string> p2)
{
	if (p1.first.first == p2.first.first)
		return p1.first.second < p2.first.second;
	return p1.first.first < p2.first.first;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<pair<pair<int, int>, string>> v; //나이, 들어온 순서, 이름 순
	int N; cin >> N;
	int a;
	string s;
	for (int i = 0; i < N; ++i)
	{
		cin >> a >> s;
		v.push_back({ { a,i },s });
	}
	sort(v.begin(), v.end(), compare);

	int size = v.size();
	for (int i = 0; i < size; ++i)
		cout << v[i].first.first << ' ' << v[i].second << '\n';
	return 0;
}