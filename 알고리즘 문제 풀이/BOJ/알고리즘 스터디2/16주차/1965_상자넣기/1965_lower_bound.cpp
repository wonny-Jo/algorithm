#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int box[1001];
vector<int> v;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> box[i];
	
	for (int i = 0; i < n; i++)
	{
		if (v.empty() || v[v.size() - 1] < box[i])
			v.push_back(box[i]);
		else
		{
			int index = lower_bound(v.begin(), v.end(), box[i]) - v.begin();
			v[index] = box[i];
		}
	}
	cout << v.size();
	return 0;
}
