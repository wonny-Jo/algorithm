#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	vector<int> v; //높이 저장
	for (int i = 0; i < N; ++i)
	{
		int a; cin >> a;
		v.push_back(a);
	}
	v.push_back(0);

	stack<int> s;
	int ret = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		while (!s.empty() && v[s.top()] >= v[i])
		{
			int x = s.top();
			s.pop();


			int width;
			if (s.empty())
				width = i;
			else
				width = i - s.top() - 1;

			ret = max(ret, v[x] * width);
		}
		s.push(i);
	}
	cout << ret;
	return 0;
}