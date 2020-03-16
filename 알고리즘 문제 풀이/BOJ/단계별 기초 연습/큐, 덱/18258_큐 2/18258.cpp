#include<iostream>
#include<queue>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N; cin >> N;
	string s;
	queue<int> q;
	int num;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		if (s.compare("push") == 0)
		{
			cin >> num;
			q.push(num);
		}
		else if (s.compare("pop") == 0)
		{
			if (q.empty())
				cout << -1<<'\n';
			else 
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s.compare("size") == 0)
			cout << q.size() << '\n';
		else if (s.compare("empty") == 0)
			cout << q.empty()<< '\n';
		else if (s.compare("front") == 0)
		{
			if (q.empty())
				cout << -1<< '\n';
			else
				cout << q.front() << '\n';
		}
		else if (s.compare("back") == 0)
		{
			if (q.empty())
				cout << -1<< '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}