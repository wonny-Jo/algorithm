#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> v;
vector<int> connected;
vector<pair<int, int>> temp;
bool c[1000001] = { 0 };

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}

	int idx = 0;
	connected.push_back(v[0]); //LIS�� ����
	temp.push_back({ idx++,v[0] }); //��ü������ ��� ��ġ�� �����ϴ��� ����
	
	for (int i = 1; i < N; i++)
	{
		if (connected[connected.size() - 1] < v[i])
		{
			connected.push_back(v[i]);
			temp.push_back({ idx++,v[i] });
			continue;
		}
		int pos = lower_bound(connected.begin(), connected.end(), v[i]) - connected.begin();
		connected[pos] = v[i];
		temp.push_back({ pos,v[i] });
	}

	//�� ��ġ���� �ϳ����� ����ΰ� �������� ����
	--idx;
	for (int i = temp.size()-1; i >= 0; i--)
	{
		if (temp[i].first == idx)
		{
			c[i] = 1;
			--idx;
		}
	}
	cout << connected.size() << '\n';
	for (int i = 0; i < temp.size(); i++)
		if (c[i])
			cout << temp[i].second << ' ';

	return 0;
}