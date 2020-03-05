#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<pair<int, string>, int> p1, pair<pair<int, string>, int> p2)
{
	if (p1.first.first == p2.first.first)
		return p1.second < p2.second;
	return p1.first.first < p2.first.first;
}

int main()
{
	int N; cin >> N;
	vector<pair<pair<int, string>,int>> v;
	int age;
	string name;
	for (int i = 0; i < N; ++i)
	{
		cin >> age >> name;
		v.push_back({ { age,name },i });
	}
	sort(v.begin(), v.end(), compare);

	for (vector<pair<pair<int, string>, int>>::iterator iter = v.begin(); iter !=v.end(); iter++)
		cout << (*iter).first.first << ' ' << (*iter).first.second << "\n";

	return 0;
}