#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int>b) //������ �ð� ���� ���� ���۽ð� ���� ��
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> meetingTime;
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		meetingTime.push_back(pair<int, int>(a, b));
	}
	sort(meetingTime.begin(), meetingTime.end(), compare); 
	int count = 1;
	int size = meetingTime.size();
	int min = meetingTime[0].second;
	for (int i = 1; i < size; ++i)
	{
		if (meetingTime[i].first >= min)
		{
			min = meetingTime[i].second;
			++count;
		}
	}
	cout << count;

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}