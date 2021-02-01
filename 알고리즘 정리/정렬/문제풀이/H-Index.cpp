#include<iostream>
///////////////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), less<int>());
	int size = citations.size();
	for (int i = 1; i <= size; i++)
	{
		if (i <= citations[size - i])
		{
			int cnt = size - i;
			for (int j = 0; j < cnt; j++)
			{
				if (citations[j] > cnt)
				{
					cnt = j;
					break;
				}
			}
			if (cnt <= i)
				answer = i;
		}
		else
			break;
	}
	return answer;
}

///////////////////////////////////////////////////

int main()
{
	cin.tie(0); cout.tie(0);
	cin.sync_with_stdio(0);

	vector<int> citations = { 3,0,6,1,5 };
	cout<<solution(citations);
	return 0;
}