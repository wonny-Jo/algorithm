#include<iostream>
//////////////////////////////////////
#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int total = brown + yellow;
	for (int i = 1; i <= sqrt(yellow); i++)
	{
		if (yellow % i == 0)
		{
			int w = i, h = yellow / i;
			if ((w + 2) * (h + 2) == total)
			{
				answer.push_back(h + 2);
				answer.push_back(w + 2);
				break;
			}
		}
	}
	return answer;
}
/////////////////////////////////////////////////
int main()
{
	vector<int> result = solution(10, 2);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
	return 0;
}