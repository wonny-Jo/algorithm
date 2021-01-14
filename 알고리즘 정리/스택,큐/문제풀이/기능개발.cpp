#include <iostream>
////////////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	while (!progresses.empty())
	{
		int d = (100 - progresses[0]) / speeds[0];
		if ((100 - progresses[0]) % speeds[0] != 0)
			++d;
		progresses.erase(progresses.begin());
		speeds.erase(speeds.begin());
		int cnt = 1;
		while (!progresses.empty() && progresses[0] + d * speeds[0] >= 100)
		{
			++cnt;
			progresses.erase(progresses.begin());
			speeds.erase(speeds.begin());
		}
		answer.push_back(cnt);
	}
	return answer;
}
////////////////////////////////////////////////////////////////////////

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int> progresses = { 93,30,55 };
	vector<int> speeds = { 1,30,5 };
	vector<int> result = solution(progresses, speeds);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
	cout << '\n';
	return 0;
}