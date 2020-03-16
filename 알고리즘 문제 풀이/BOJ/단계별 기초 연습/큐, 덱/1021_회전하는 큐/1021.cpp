#include<iostream>
#include<deque>
using namespace std;
deque<int> dq;

void MoveRight(int pos)
{
	for (int i = 0; i < pos; ++i)
	{
		dq.push_back(dq.front());
		dq.pop_front();
	}
}

void MoveLeft(int pos)
{
	for (int i = 0; i < pos; ++i)
	{
		dq.push_front(dq.back());
		dq.pop_back();
	}
}

int main()
{
	int N, M; cin >> N >> M;
	int moveNum = 0;
	for (int i = 1; i <= N; ++i)
		dq.push_back(i);
	int arr[51];
	for (int i = 0; i < M; ++i)
	{
		cin >> arr[i];
		int size = dq.size();
		int pos;
		for (pos = 0; pos < size; pos++)
		{
			if (dq[pos] == arr[i])
				break;
		}
		if (pos < size - pos)
		{
			MoveRight(pos);
			moveNum += pos;
		}
		else
		{
			MoveLeft(size - pos);
			moveNum += size - pos;
		}
		dq.pop_front();
	}
	cout << moveNum;

	return 0;
}