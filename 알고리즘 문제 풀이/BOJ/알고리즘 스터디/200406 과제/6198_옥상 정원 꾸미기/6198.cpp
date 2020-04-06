#include<iostream>
#include<stack>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N; cin >> N;
	long long arr[80001];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	arr[N] = 1000000000;
	stack<long long> s;
	long long ret = 0;
	for (int i = 0; i <= N; ++i)
	{
		while (!s.empty() && arr[s.top()] <= arr[i])
		{
			long long x = s.top();
			s.pop();
			ret += i - x - 1;
		}
		s.push(i);
	}
	cout << ret;
	return 0;
}