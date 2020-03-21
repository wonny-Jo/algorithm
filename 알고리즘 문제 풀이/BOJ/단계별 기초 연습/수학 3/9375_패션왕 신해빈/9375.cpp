#include<iostream>
#include<vector>
using namespace std;

int arr[1001][1001] = { 0 };

int main()
{
	int T, N; cin >> T;
	for (int i = 0; i < T; ++i)
	{
		vector<pair<string, int>> v;
		cin >> N;
		for (int j = 0; j < N; ++j)
		{
			string s;
			cin >> s >> s;
			bool c = false;
			int k = 0;
			int size = v.size();
			while (k<size)
			{
				if (v[k].first == s)
				{
					++v[k].second;
					c = true;
					break;
				}
				++k;
			}
			if (!c)
				v.push_back({ s,2 });
		}

		int size = v.size();
		int result = 1;
		for (int j = 0; j < size; ++j)
			result *= v[j].second;
		cout << result - 1 << endl;
	}
	

	
	
	return 0;
}