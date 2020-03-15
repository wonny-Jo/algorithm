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
	for (int i = 1; i <= N; ++i) //�Էµ� ������ ����
	{
		for (int j = K; j >= 1; --j) //�� ������ ���Ը� Ȯ���Ͽ� ������Ʈ
		//�̶� K���� ���� ������ �ݴ�� ���� ������Ʈ ���Ŀ� �����͵��� ������ �޾Ƽ� �� ������ �ι� ����ϴ� ��찡 �߻�.
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