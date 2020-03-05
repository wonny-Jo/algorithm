#include<iostream>
using namespace std;
#include<string.h>


class stack
{
private:
	int* data;
	int data_max_size;
	int data_count;

public:
	stack():data_max_size(10),data_count(0)
	{
		data = new int[data_max_size];
	}
	~stack(){}

	void push(int x)
	{
		if (data_count >= data_max_size)
		{
			data_max_size *=2;
			int* temp = new int[data_max_size];
			memcpy(temp, data, sizeof(int) * data_count);
			delete data;
			data = temp;
		}
		data[data_count] = x;
		++data_count;
	}

	int pop()
	{
		if (empty())
		{
			return -1;
		}

		--data_count;
		return data[data_count];
	}

	int size()
	{
		return data_count;
	}

	int empty()
	{
		if (data_count<0)
		{
			return -1;
		}
		else if (!data_count)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int top()
	{
		if (empty())
		{
			return -1;
		}
		return data[data_count-1];
	}
};

int main()
{
	int N;
	cin >> N;
	stack stac;
	for (int i = 0; i < N; i++)
	{
		char command[100];
		cin >> command;
		if (!strcmp(command, "push"))
		{
			int number;
			cin >> number;
			stac.push(number);
		}
		else if (!strcmp(command, "top"))
		{
			cout << stac.top() << endl;
		}
		else if (!strcmp(command, "pop"))
		{
			cout << stac.pop()<<endl;
		}
		else if (!strcmp(command, "size"))
		{
			cout << stac.size()<<endl;
		}
		else if (!strcmp(command, "empty"))
		{
			cout << stac.empty()<<endl;
		}
	}

	return 0;
}