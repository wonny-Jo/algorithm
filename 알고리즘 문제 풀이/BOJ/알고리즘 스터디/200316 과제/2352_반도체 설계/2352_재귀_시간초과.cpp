#include<iostream>
using namespace std;
int result = 0;
int connect[40001];
int N;

int max(int a, int b)
{
	return a > b ? a : b;
}

int connection(int startNum, int endNum, int count)
{
	if (startNum > N)
		return count;

	int ret = count;
	for (int i = startNum; i <= N; ++i)
	{
		if (connect[i] > endNum)
			ret = max(ret, connection(i + 1, connect[i], count + 1));
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> connect[i];
	cout << connection(1, 0, 0);

	return 0;
}