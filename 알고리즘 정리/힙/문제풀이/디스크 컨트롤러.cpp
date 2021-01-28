#include<iostream>

////////////////////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp
{
	bool operator()(vector<int> a, vector<int> b)
	{
		return a.at(1) > b.at(1);
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0, i = 0, time = 0;
	sort(jobs.begin(), jobs.end());
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	while (i < jobs.size() || !pq.empty()) 
	{
		if (jobs.size() > i && time >= jobs[i][0])
		{
			pq.push(jobs[i]);
			i++;
			continue;
		}
		if (!pq.empty())
		{
			time += pq.top()[1];
			answer += time - pq.top()[0];
			pq.pop();
		}
		else 
			time = jobs[i][0];
	}
	return answer / jobs.size();
}
////////////////////////////////////////////////////////

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<vector<int>> jobs = { {0,3},{1,9},{2,6} };
	cout << solution(jobs);
	return 0;
}