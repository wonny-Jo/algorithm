#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int sum = 0, result = -10000;
	int num[100001];
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
		sum += num[i];
		result = result > sum ? result : sum;
		if (sum < 0)
			sum = 0;
	}
	cout << result;
	return 0;
}