#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


// 오름차순
int compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main()
{
	int N;
	cin >> N;
	int *data=new int[N];

	for (int i = 0; i < N; i++)
		cin >> data[i];
	qsort(data, N, sizeof(int),compare);
	for (int i = 0; i < N; i++)
		cout << data[i]<<"\n";
	delete data;
	return 0;
}