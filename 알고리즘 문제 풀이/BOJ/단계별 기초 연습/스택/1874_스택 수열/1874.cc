#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int num=0,input;
	int pop_count = 0;
	stack<int> stack_int;
	queue<int> queue_int;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		if (num < input)
		{
			if (pop_count)
			{
				queue_int.push(pop_count);
				pop_count = 0;
			}
			queue_int.push(input - num);
		}
		while (num < input)
		{
			++num;
			stack_int.push(num);
		}
		if (stack_int.top() == input)
		{
			stack_int.pop();
			++pop_count;
		}
		else
		{
			cout << "NO" << "\n";
			return 0;
		}
	}
	int temp = n;
	int tem = queue_int.front();
	queue_int.pop();
	for (int i = 0; i < tem; ++i)
		cout << '+' << "\n";
	while (!queue_int.empty())
	{
		tem = queue_int.front();
		queue_int.pop();
		for (int i = 0; i < tem; ++i)
			cout << '-' << "\n";
		temp -= tem;
		tem = queue_int.front();
		queue_int.pop();
		for (int i = 0; i < tem; ++i)
			cout << '+' << "\n";

	}
	for (int i = 0; i < temp; ++i)
		cout << '-' << "\n";
	return 0;
}