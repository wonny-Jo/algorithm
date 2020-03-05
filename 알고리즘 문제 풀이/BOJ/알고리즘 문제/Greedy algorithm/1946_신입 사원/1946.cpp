#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int N;
	int a,b;
	for (int i = 0; i < T; ++i)
	{
		vector<pair<int, int>> v;
		cin >> N;
		for (int j = 0; j < N; ++j)
		{
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int size = v.size();
		int cnt = 0;
		int min = v[0].second;
		for (int j = 1; j < size; ++j)
		{
			if (v[j].second > min)
				++cnt;
			else
				min = v[j].second;
		}
		cout << size - cnt << endl;
	}


	return 0;
}