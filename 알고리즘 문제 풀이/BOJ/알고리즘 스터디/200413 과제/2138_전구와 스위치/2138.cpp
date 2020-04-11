#include<iostream>
using namespace std;

void pushSwitch(char &c)
{
	if (c == '0')
		c = '1';
	else
		c = '0';
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	string start, end;
	cin >> start >> end;
	string start2 = start;
	int result = 0;
	//처음 위치는 움직임 없이.
	for (int i = 1; i < N-1; ++i)
	{
		if (start[i - 1] != end[i - 1])
		{
			pushSwitch(start[i - 1]);
			pushSwitch(start[i]);
			pushSwitch(start[i + 1]);
			++result;
		}
	}
	if (start[N - 2] != end[N - 2])
	{
		pushSwitch(start[N - 2]);
		pushSwitch(start[N-1]);
		++result;
	}

	if (start == end)
	{
		cout << result;
		return 0;
	}

	//처음 위치를 한번 바꾸고 시작
	result = 1;
	pushSwitch(start2[0]);
	pushSwitch(start2[1]);
	for (int i = 1; i < N - 1; ++i)
	{
		if (start2[i - 1] != end[i - 1])
		{
			pushSwitch(start2[i - 1]);
			pushSwitch(start2[i]);
			pushSwitch(start2[i + 1]);
			++result;
		}
	}
	if (start2[N - 2] != end[N - 2])
	{
		pushSwitch(start2[N - 2]);
		pushSwitch(start2[N - 1]);
		++result;
	}

	if (start2 == end)
		cout << result;
	else
		cout << -1;

	return 0;
}