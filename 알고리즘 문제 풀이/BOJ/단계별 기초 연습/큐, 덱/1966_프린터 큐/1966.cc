#include<iostream>
using namespace std;
#include<queue>
//class Queue
//{
//private:
//	int* data;
//	int data_max_size;
//	int data_count;
//	int start_position;
//
//public:
//	Queue():data_max_size(10),data_count(0), start_position(0)
//	{
//		data = new int[data_max_size];
//	}
//	~Queue(){}
//
//	void push(int x)
//	{
//		if (data_count >= data_max_size)
//		{
//			data_max_size *=2;
//			int* temp = new int[data_max_size];
//			memcpy(temp, data, sizeof(int) * data_count);
//			delete data;
//			data = temp;
//		}
//		data[data_count] = x;
//		++data_count;
//	}
//
//	int pop()
//	{
//		if (empty())
//		{
//			return -1;
//		}
//		++start_position;
//		return data[start_position-1];
//	}
//
//	int size()
//	{
//		return data_count-start_position;
//	}
//
//	int empty()
//	{
//		if (data_count<start_position)
//		{
//			return -1;
//		}
//		else if (data_count==start_position)
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//	int front()
//	{
//		if (empty())
//		{
//			return -1;
//		}
//		return data[start_position];
//	}
//	int back()
//	{
//		if (empty())
//		{
//			return -1;
//		}
//		return data[data_count-1];
//
//	}
//};

int main()
{
	int T;
	cin >> T;
	int input, curr, count;
	for (int i = 0; i < T; i++)
	{
		int N, M;
		cin >> N >> M;
		queue<int> que;
		int count_num[10] = { 0 };
		count = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> input;
			que.push(input);
			++count_num[input];
			if (j == M)
				curr = input;
		}
		for (int j = 9; j > curr; j--)
		{
			while (count_num[j])
			{
				if (que.front() == j)
				{
					que.pop();
					++count;
					--count_num[j];
				}
				else
				{
					que.push(que.front());
					que.pop();
				}
				if (M == 0)
					M = que.size();
				--M;
			}
		}
		for (int j = 0; j < M; j++)
		{
			if (que.front() == curr)
				++count;
			que.pop();
		}
		cout << count + 1 << endl;
	}
	return 0;
 } 