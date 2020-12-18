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
	vector<pair<pair<int, int>, int>> v; //보내는 곳, 받는 곳, 박스 개수
	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}

	sort(v.begin(), v.end(), compare); //도착지점 우선 오름차순 정렬
	int arr[2001] = { 0 }; //마을의 위치를 지날때마다 가지고있는 박스 수
	int ret = 0; //전체 박스 수

	//각 지정된 것마다 옮길수 있는 최대수를 구해 추가해준다.
	for (int i = 0; i < M; i++)
	{
		int minBox = 100000; //지정된 이동거리중 박스의 여유분이 가장 작은것 체크
		for (int j = v[i].first.first; j < v[i].first.second; j++)
			minBox = min(minBox, C - arr[j]);
		int maxBox = min(minBox, v[i].second); //옮길수 있는 최대 수
		ret += maxBox;
		for (int j = v[i].first.first; j < v[i].first.second; j++)
			arr[j] += maxBox;
	}
	cout << ret;
	return 0;
}
