#include<iostream>

///////////////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int i = 0, j = people.size() - 1;
	while (i <= j)
	{
		if (people[i] + people[j] <= limit)
			i++;
		j--;
		answer++;
	}
	return answer;
}

///////////////////////////////////////////////////

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int> people = { 70,50,80,50 };
	int limit = 100;
	cout << solution(people, limit);
	return 0;
}