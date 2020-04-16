#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int M; cin >> M;
	int S = 0;
	for (int i = 0; i < M; ++i)
	{
		string s; cin >> s;
		int X;
		if (s == "add")
		{
			cin >> X; S = S | 1 << X;
		}
		else if (s == "remove")
		{
			cin >> X; S = S & ~(1 << X);
		}
		else if (s == "check")
		{
			cin >> X;
			if (S & (1 << X))	cout << 1;
			else	cout << 0;
			cout << '\n';
		}
		else if (s == "toggle")
		{
			cin >> X; S = S ^ (1 << X);
		}
		else if (s == "all")
			for (int j = 1; j <= 20; ++j)
				S = S | (1 << j);
		else if (s == "empty")
			S = 0;
	}

	return 0;
}