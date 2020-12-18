#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if (a.first.first == b.first.first && a.first.second == b.first.second)
		return a.second > b.second;
	if (a.first.second == b.first.second)
		return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, C, M; cin >> N >> C >> M;
	vector<pair<pair<int, int>, int>> v; //������ ��, �޴� ��, �ڽ� ����
	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}

	sort(v.begin(), v.end(), compare); //�������� �켱 �������� ����
	int arr[2001] = { 0 }; //������ ��ġ�� ���������� �������ִ� �ڽ� ��
	int ret = 0; //��ü �ڽ� ��

	//�� ������ �͸��� �ű�� �ִ� �ִ���� ���� �߰����ش�.
	for (int i = 0; i < M; i++)
	{
		int minBox = 100000; //������ �̵��Ÿ��� �ڽ��� �������� ���� ������ üũ
		for (int j = v[i].first.first; j < v[i].first.second; j++)
			minBox = min(minBox, C - arr[j]);
		int maxBox = min(minBox, v[i].second); //�ű�� �ִ� �ִ� ��
		ret += maxBox;
		for (int j = v[i].first.first; j < v[i].first.second; j++)
			arr[j] += maxBox;
	}
	cout << ret;
	return 0;
}
