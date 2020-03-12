#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	int N; cin >> N;
	int connectLine[40001],cache[40001];
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
			int temp = lower_bound(cache + 1, cache + 1 + size, connectLine[i]) - cache; //iterator 반환이라서 처음위치의 iterator를 빼준게 해당 위치 index
			cache[temp] = connectLine[i];
		}
	}
	cout << size;
	return 0;
}