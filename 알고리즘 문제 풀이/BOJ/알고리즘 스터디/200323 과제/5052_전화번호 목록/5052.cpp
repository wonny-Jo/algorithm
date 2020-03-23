#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int t; cin >> t;
	for (int i = 0; i < t; ++i)
	{
		vector<string> v; //모든 string을 저장
		int n; cin >> n;
		string s;
		bool isYes = true;
		for (int j = 0; j < n; ++j)
		{
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end()); //오름차순 정렬을 통해서 순차적으로 정렬
		for (int j = 0; j < n-1; ++j)
		{
			if (v[j].size() >= v[j + 1].size()) //v[j]가 v[j+1]보다 길이가 큰 경우는 부분이 같을 수 없다. 길이가 같은 경우는 없다고 문제에 나와있다.
				continue;
			if (v[j] == v[j + 1].substr(0,v[j].size()))
			{
				isYes = false;
				break;
			}
		}
		if (isYes)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}