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
	vector<long long> v;
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		long long a; cin >> a;
		v.push_back(a);
	}
	v.push_back(0);

	stack<long long> s; //히스토그램 위치 저장
	long long ret = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		//남은 저장된 위치 중 최근에 저장된 것의 높이가 v[i]보다 크면
		//이 높이를 기준으로한 사각형은 계산 종결.
		while (!s.empty() && v[s.top()] >= v[i])
		{
			long long j = s.top();
			s.pop();
			long long width;
			//s에 남은게 없다면 가로축의 길이는 현재 i가 길이가 된다.
			if (s.empty())
				width = i;
			//s에 남은게 있다면 그 위치가 가로 길이중 왼쪽의 끝이다.
			else
				width = i - s.top() - 1;
			ret = max(ret, v[j] * width);
		}
		s.push(i);
	}
	cout << ret;
	return 0;
}