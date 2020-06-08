#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int N;
vector<pair<int, int>> v;
vector<int> connected;
vector<pair<int, int>> temp;
bool c[500001] = { 0 };

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int idx = 0;
	connected.push_back(v[0].second); //LIS의 값들
	temp.push_back({ idx++,v[0].first }); //전체적으로 어느 위치에 접근하는지 저장
	
	for (int i = 1; i < N; i++)
	{
		if (connected[connected.size() - 1] < v[i].second)
		{
			connected.push_back(v[i].second);
			temp.push_back({ idx++,v[i].first });
			continue;
		}
		int pos = lower_bound(connected.begin(), connected.end(), v[i].second) - connected.begin();
		connected[pos] = v[i].second;
		temp.push_back({ pos,v[i].first });
	}

	//각 위치마다 하나씩만 살려두고 나머지는 버림
	--idx;
	for (int i = temp.size()-1; i >= 0; i--)
	{
		if (temp[i].first == idx)
		{
			c[temp[i].second] = 1;
			--idx;
		}
	}
	cout << temp.size() - connected.size() << '\n';
	for (int i = 0; i < temp.size(); i++)
		if (!c[temp[i].second])
			cout << temp[i].second << '\n';

	return 0;
}