#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}


int main()
{
	int N; cin >> N;
	int arr[1001];
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	int increase[1001];
	int decrease[1001];
	increase[1] = arr[1];
	int increaseSize = 1, decreaseSize = 0;
	int maxSize = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (increase[increaseSize] < arr[i])
		{
			++increaseSize;
			increase[increaseSize] = arr[i];
		}
		else
		{
			int index = lower_bound(increase+1, increase + increaseSize, arr[i]) - increase;
			increase[index] = arr[i];
		}

		decrease[0] = arr[i];
		decreaseSize = 0;
		for (int j = i + 1; j <= N; ++j)
		{
			if (decrease[decreaseSize] > arr[j])
			{
				++decreaseSize;
				decrease[decreaseSize] = arr[j];
			}
			else
			{
				int index = lower_bound(decrease, decrease + decreaseSize, arr[j], compare) - decrease;
				decrease[index] = arr[j];
			}
		}
		maxSize = maxSize > increaseSize + decreaseSize ? maxSize : increaseSize + decreaseSize;
	}
	cout << maxSize;
	return 0;
}