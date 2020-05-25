#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N; cin >> N;
	priority_queue<int, vector<int>, greater<int>> posMan, posWoman, negMan, negWoman;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		if (num < 0)
			negMan.push(abs(num));
		else
			posMan.push(num);
	}

	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		if (num < 0)
			negWoman.push(abs(num));
		else
			posWoman.push(num);
	}

	int ret = 0;
	int male, female;
	while (1) //
	{
		if (posMan.empty() || negWoman.empty())
			break;
		male = posMan.top();
		female = negWoman.top();
		negWoman.pop();
		if (male < female)
		{
			++ret;
			posMan.pop();
		}
	}

	while (1)
	{
		if (negMan.empty() || posWoman.empty())
			break;
		male = negMan.top();
		female = posWoman.top();
		negMan.pop();

		if (male > female)
		{
			++ret;
			posWoman.pop();
		}
	}
	cout << ret;
	return 0;
}