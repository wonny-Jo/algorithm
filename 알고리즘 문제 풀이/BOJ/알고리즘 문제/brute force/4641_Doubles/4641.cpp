#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	while (1)
	{
		int number[17];
		int size = 0;
		while (1)
		{
			cin >> number[size];
			if (number[size] == -1)
				return 0;
			if (number[size] == 0)
				break;
			++size;
		}
		sort(number, number + size);
		int count = 0;
		for (int i = 0; i < size-1; ++i)
		{
			for (int j = i+1; j < size; ++j)
			{
				if (2 * number[i] < number[j])
					break;
				else if (2 * number[i] == number[j])
					++count;
			}
		}
		cout << count << endl;
	}
	return 0;
}