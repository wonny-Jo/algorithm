#include<iostream>
using namespace std;
#include<stack>

//class stack
//{
//private:
//	int* data;
//	int data_max_size;
//	int data_count;
//
//public:
//	stack():data_max_size(10),data_count(0)
//	{
//		data = new int[data_max_size];
//	}
//	~stack(){}
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
//
//		--data_count;
//		return data[data_count];
//	}
//
//	int size()
//	{
//		return data_count;
//	}
//
//	int empty()
//	{
//		if (data_count<0)
//		{
//			return -1;
//		}
//		else if (!data_count)
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//	int top()
//	{
//		if (empty())
//		{
//			return -1;
//		}
//		return data[data_count-1];
//	}
//};

int main()
{
	int N;
	cin >> N;
	stack<int> stac;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 0)
			stac.pop();
		else
			stac.push(num);
	}
	int sum = 0;
	while (!stac.empty())
	{
		sum += stac.top();
		stac.pop();
	}
	cout << sum << endl;

	return 0;
}