#include<iostream>
using namespace std;

int main()
{
	int N,X;
	cin >> N>>X;
	int* num=new int[N];
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < N; i++)
	{
		if (num[i]<X)
			cout << num[i]<<" ";
	}
	return 0;
}
