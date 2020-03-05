#include<iostream>
using namespace std;
int N;
int T[16] = { 0 }, P[16] = { 0 };
bool visited[16] = { 0 };

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// 각 루트마다의 값을 비교하여 최대값을 반환하는 문제
int searchMax(int day,int currentPay)
{
	if (day >= N)
		return currentPay;
	
	int ret = 0;
	for (int i = day; i < N; ++i)
	{
		visited[i] = true;
		ret = max(ret,searchMax(i + T[i], currentPay + P[i]));
		visited[i] = false;
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> T[i] >> P[i];
		if (i + T[i] > N)
			P[i] = 0;
	}
	cout << searchMax(0,0) << endl;
	
	return 0;
}