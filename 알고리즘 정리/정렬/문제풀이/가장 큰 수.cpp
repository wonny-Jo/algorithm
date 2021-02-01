#include<iostream>
///////////////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string temp[100001];
bool compare(string a, string b)
{
	int len = a.size() < b.size() ? a.size() : b.size();
	if (a.substr(0, len).compare(b.substr(0, len)))
		return a > b;

	string s1 = a, s2 = b;
	while (s1.size() < 4)
		s1 += s1;
	while (s2.size() < 4)
		s2 += s2;
	return s1.substr(0, 4) > s2.substr(0, 4);
}

string solution(vector<int> numbers) {
	string answer = "";
	bool isEnd = true;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] != 0)
			isEnd = false;
		temp[i] = to_string(numbers[i]);
	}
	if (isEnd)
		return "0";

	sort(temp, temp + numbers.size(), compare);
	for (int i = 0; i < numbers.size(); i++)
		answer += temp[i];
	return answer;
}

///////////////////////////////////////////////////

int main()
{
	cin.tie(0); cout.tie(0);
	cin.sync_with_stdio(0);

	vector<int> numbers = { 6,10,2 };
	cout<<solution(numbers);
	return 0;
}