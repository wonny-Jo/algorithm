#include<iostream>
using namespace std;

int N, S;
int number[21];
int cnt = 0;
int search(int num, int sum)
{
	if (num == N)
		return 0;


	for (int i = num; i < N; ++i)
	{
		if (sum+number[i] == S)
			++cnt;
		search(i + 1, sum+ number[i]);
	}
	return cnt;
}

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		cin >> number[i];
	cout << search(0, 0);
	return 0;
}