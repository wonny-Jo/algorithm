#include<iostream>
#include<vector>
#include<deque>
using namespace std;
bool c[101] = { 0 };
vector<long long> v;

int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long a; cin >> a;
		v.push_back(a);
	}
	
	deque<long long> dq;
	dq.push_front(v[0]);
	c[0] = 1;
	//앞으로 연결
	while (1)
	{
		int i;
		for (i = 1; i < N; i++)
			if (!c[i])
				if (dq.front() * 3 == v[i] || dq.front() == v[i] * 2)
				{
					dq.push_front(v[i]);
					c[i] = 1;
					break;
				}
		if (i == N)
			break;
	}
	//뒤로 연결
	while (1)
	{
		int i;
		for (i = 1; i < N; i++)
			if (!c[i])
				if (dq.back() * 2 == v[i] || dq.back() == v[i] * 3)
				{
					dq.push_back(v[i]);
					c[i] = 1;
					break;
				}
		if (i == N)
			break;
	}

	for (int i = 0; i < N; ++i)
		cout << dq[i] << ' ';

	return 0;
}