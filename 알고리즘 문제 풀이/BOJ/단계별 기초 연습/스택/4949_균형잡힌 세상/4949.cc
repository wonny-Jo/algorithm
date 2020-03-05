#include<iostream>
using namespace std;
#include<stack>
#include<string.h>
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
	char s[300];
	char input;
	while (cin.getline(s, sizeof(s))) {
		
		stack<char> stac;
		input = s[0];
		if (input == '.')
			break;
		int i = 0;
		int length = strlen(s);
		while (i<length)
		{
			input = s[i];
			if (input == '.')
				break;
			if (input == '(')
				stac.push('(');
			else if (input == '[')
				stac.push('[');
			else if (input == ')')
			{
				if (stac.empty() || (!stac.empty() && stac.top() == '['))
				{
					stac.push('*');
					break;
				}
				if (stac.top() == '(')
					stac.pop();
			}
			else if (input == ']')
			{
				if (stac.empty() || (!stac.empty() && stac.top() == '('))
				{
					stac.push('*');
					break;
				}
				if (stac.top() == '[')
					stac.pop();
			}
			++i;
		}
		if (stac.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
 }