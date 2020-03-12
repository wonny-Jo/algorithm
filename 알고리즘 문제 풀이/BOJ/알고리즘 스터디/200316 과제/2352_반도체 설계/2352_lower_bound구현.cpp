#include<iostream>
using namespace std;
int N;
int connectLine[40001], cache[40001];
int lower_bound(int* arr, int n, int value) //인덱스 반환
{
	int start = 0;
	int end = n-1;

	int mid = n-1;
	while (end - start > 0)
	{
		mid = (start + end) / 2;
		if (arr[mid] < value)
			start = mid + 1;
		else
			end = mid;
	}
	return end + 1;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> connectLine[i];
	cache[1] = connectLine[1];
	int size = 1;
	for (int i = 2; i <= N; ++i)
	{
		if (cache[size] < connectLine[i])
		{
			++size;
			cache[size] = connectLine[i];
		}
		else
		{
			int temp = lower_bound(cache + 1, size, connectLine[i]); //iterator 반환이라서 처음위치의 iterator를 빼준게 해당 위치 index
			cache[temp] = connectLine[i];
		}
	}
	cout << size;
	return 0;
}