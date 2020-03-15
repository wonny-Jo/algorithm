#include<iostream>
using namespace std;
int arr[1000001];
int N;

int searchMaxPos(int start)
{
	int max = 0,max_pos;
	for (int i = start; i < N; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
			max_pos = i;
		}
	}
	return max_pos;
}

long long sumPart(int start, int maxPos)
{
	long long sum = 0;
	for (int i = start; i < maxPos; ++i)
		sum += arr[maxPos] - arr[i];
	return sum;
}

int main()
{
	int T; cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		 cin >> N;
		for (int j = 0; j < N; ++j)
			cin >> arr[j];
		int start = 0;
		long long totalSum = 0;
		while (start < N)
		{
			int maxPos = searchMaxPos(start);
			totalSum += sumPart(start, maxPos);
			start = maxPos + 1;
		}
		cout << '#' << i << ' ' << totalSum << endl;
	}

	return 0;
}