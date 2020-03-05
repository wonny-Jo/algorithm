#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	int weight[100001] = { 0 };
	for (int i = 0; i < N; ++i)
		cin>>weight[i];
	sort(weight, weight + N);
	int max = 0;
	for (int i = 0; i < N; ++i)
	{
		if (max < weight[i] * (N - i))
			max = weight[i] * (N - i);
	}
	cout << max;

	return 0;
}