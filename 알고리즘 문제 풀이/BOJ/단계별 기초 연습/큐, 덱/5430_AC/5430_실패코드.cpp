#include<iostream>
#include<deque>
using namespace std;
deque<int> dq;
bool R;
bool hasError;

void Delete()
{
	if (!R)
		dq.pop_front();
	else
		dq.pop_back();
}

void print()
{
	if (hasError)
	{
		cout << "error" << endl;
		return;
	}
	if (dq.empty())
	{
		return;
	}
	if (!R)
	{
		cout << '['<<dq.front();
		dq.pop_front();
		while (!dq.empty())
		{
			cout << ',' << dq.front();
			dq.pop_front();
		}
	}
	else
	{
		cout << '[' << dq.back();
		dq.pop_back();
		while (!dq.empty())
		{
			cout << ',' << dq.back();
			dq.pop_back();
		}
	}
	cout << ']' << endl;
}

int main()
{
	int T; cin >> T;
	string p, s; int n;
	for (int i = 1; i <= T; ++i)
	{
		hasError = false; R = false;
		cin >> p; cin >> n;
		char a;
		int num;
		for (int i = 0; i < n; ++i)
		{
			cin >> a; cin >> num;
			dq.push_back(num);
		}
		cin >> a;
		int p_size = p.size();
		for (int j = 0; j < p_size; ++j)
		{
			if (p[j] == 'R')
				R = !R;
			else if (p[j] == 'D')
			{
				if (dq.empty())
				{
					hasError = true;
					break;
				}
				Delete();
			}
		}
		print();
	}

	return 0;
}