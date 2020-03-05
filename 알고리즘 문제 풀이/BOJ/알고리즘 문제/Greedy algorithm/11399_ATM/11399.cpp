#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	int P[1001] = { 0 };
	for (int i = 0; i < N; ++i)
		cin >> P[i];
	sort(P, P + N);
	int time[1001] = { 0 };
	time[0] = P[0];
	int sum = time[0];
	for (int i = 1; i < N; ++i)
	{
		time[i] = time[i - 1] + P[i];
		sum += time[i];
	}
	cout << sum << endl;
	return 0;
}