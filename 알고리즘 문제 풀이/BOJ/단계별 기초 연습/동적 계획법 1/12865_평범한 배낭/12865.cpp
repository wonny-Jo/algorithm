#include<iostream>
#include<string.h>
using namespace std;
int N, K;
int W[101];
int V[101];
int cache[100001];

int max(int a, int b)
{
	return a > b ? a : b;
}

int search()
{
	for (int i = 1; i <= N; ++i) //입력된 물건의 개수
	{
		for (int j = K; j >= 1; --j) //각 물건의 무게를 확인하여 업데이트
		//이때 K부터 도는 이유는 반대로 돌면 업데이트 된후에 다음것들이 영향을 받아서 한 물건을 두번 사용하는 경우가 발생.
		{
			if (W[i] <= j)
				cache[j] = max(cache[j], cache[j - W[i]] + V[i]);
		}
	}

	return cache[K];
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		cin >> W[i] >> V[i];
	memset(cache, 0, sizeof(cache));

	cout<<search();
	return 0;
}