#include<iostream>
using namespace std;
#include<queue>
#include<string.h>
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
	queue<int> Que;
	queue<int> Que_result;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		Que.push(i);
	while (!Que.empty())
	{
		for (int i = 1; i < K; ++i)
		{
			Que.push(Que.front());
			Que.pop();
		}
		Que_result.push(Que.front());
		Que.pop();
	}
	cout << '<'<<Que_result.front();
	Que_result.pop();
	while (!Que_result.empty())
	{
		cout<<", " << Que_result.front();
		Que_result.pop();
	}
	cout << '>';
	return 0;
 }