#include<iostream>
using namespace std;
#include<string.h>
#include<deque>

int main()
{
	int N;
	cin >> N;
	deque<int> deq;
	for (int i = 0; i < N; i++)
	{
		char s[20];
		cin >> s;
		if (!strcmp(s, "push_front"))
		{
			int num;
			cin >> num;
			deq.push_front(num);
		}
		else if (!strcmp(s, "push_back"))
		{
			int num;
			cin >> num;
			deq.push_back(num);
		}
		else if (!strcmp(s, "pop_front"))
		{
			if (deq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << deq.front() << endl;
				deq.pop_front();
			}
		}
		else if (!strcmp(s, "pop_back"))
		{
			if (deq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << deq.back() << endl;
				deq.pop_back();
			}
		}
		else if (!strcmp(s, "size"))
		{
			cout<<deq.size()<<endl;
		}
		else if (!strcmp(s, "empty"))
		{
			cout << deq.empty()<<endl;
		}
		else if (!strcmp(s, "front"))
		{
			if (deq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << deq.front() << endl;
			}
		}
		else if (!strcmp(s, "back"))
		{
			if (deq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << deq.back() << endl;
			}
		}
	}

	return 0;
 } 