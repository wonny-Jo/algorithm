#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int k; cin >> k;
	bool c[10];
	for (int i = 0; i < k; ++i)
	{
		char s;
		cin >> s;
		if (s == '<') c[i] = 0;
		else c[i] = 1;
	}
	
	int pos = 0;
	char max_result[11] = { 0 };
	int num = 9;
	stack<int> max;
	max.push(num);
	for (int i = 0; i <k; ++i)
	{
		--num;
		if (c[i] == 0)
			max.push(num);
		else
		{
			while (!max.empty())
			{
				max_result[pos]= max.top()+'0';
				++pos;
				max.pop();
			}
			max.push(num);
		}
	}
	while (!max.empty())
	{
		max_result[pos] = max.top() + '0';
		++pos;
		max.pop();
	}


	pos = 0;
	char min_result[11] = { 0 };
	num = 0;
	stack<int> min;
	min.push(num);
	for (int i = 0; i <k ; ++i)
	{
		++num;
		if (c[i] == 1)
			min.push(num);
		else 
		{
			while (!min.empty())
			{
				min_result[pos] = min.top() + '0';
				++pos;
				min.pop();
			}
			min.push(num);
		}
	}
	while (!min.empty())
	{
		min_result[pos] = min.top() + '0';
		++pos;
		min.pop();
	}

	cout << max_result << endl << min_result << endl;
	return 0;
}