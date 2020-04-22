#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int remainBox[2001];
int N, C;
vector<pair<pair<int,int>,int>> v;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if (a.first.second == b.first.second && a.first.first == b.first.first)
		return a.second > b.second;
	if (a.first.second == b.first.second)
		return a.first.first > b.first.first;
	return a.first.second < b.first.second;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;
	int M; cin >> M;
	for (int i = 1; i <= N; ++i)
		remainBox[i] = C;
	
	for (int i = 0; i < M; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}
	sort(v.begin(), v.end(), compare);
	int sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		int minRemain = 10000; //�̵��Ÿ��� ������ �ڽ������� ���� ������ üũ
		for (int j = v[i].first.first; j < v[i].first.second; j++)
			minRemain = min(minRemain, remainBox[j]);
	
		int maxBox = min(minRemain, v[i].second); //�ű�� �ִ� �ִ� �ڽ� ��
		sum +=maxBox;
		for (int j = v[i].first.first; j < v[i].first.second; j++)
			remainBox[j] -= maxBox;
	}

	cout << sum;

	return 0;
}