#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair < pair<int, int>,int> a, pair < pair<int, int>,int>b) //끝나는 시간 먼저 비교후 시작시간 기준 비교
{
	/*if ((a.first.second == b.first.second)&&(a.second == b.second))
		return a.first.first < b.first.first;*/
	if (a.first.second == b.first.second)
		return a.second > b.second;
	return a.first.second < b.first.second;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<pair<int, int>, int>> data;
	int endTime, pay;
	for (int i = 1; i <= N; ++i)
	{
		cin >> endTime >> pay;
		if (i + endTime <= N+1)
		{
			pair<int, int> time(i, i+endTime);
			data.push_back(pair<pair<int, int>, int>(time, pay));
		}
	}
	sort(data.begin(), data.end(), compare);

	int sumDate[16] = { 0 };
	int size = data.size();
	int result = 0, final_pos = 0;;
	for (int i = 0; i < size; ++i)
	{ 
		if (sumDate[data[i].first.second] < sumDate[data[i].first.first] + data[i].second)
		{
			sumDate[data[i].first.second] = sumDate[data[i].first.first] + data[i].second;
			if (result < sumDate[data[i].first.second])
				result = sumDate[data[i].first.second];
			for (int k = data[i].first.second; k < 16; ++k)
				sumDate[k] = result;
		}
	}

	cout << result;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}