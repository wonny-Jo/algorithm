#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1)
	{
		int N; cin >> N;
		if (N == 0)
			break;
		vector<long long> v; //높이를 순서대로 저장
		for (int i = 0; i < N; ++i)
		{
			long long a; cin >> a;
			v.push_back(a);
		}
		v.push_back(0); //마지막에 스택에 오름차순으로 쌓은 것들에서 최대넓이를 구하기위해서 넣어줌

		stack<long long> s; //현재의 벡터위치보다 더 높은값을 가지는 이전 벡터위치들을 저장
		long long ret = 0; //가장 넓은 직사각형의 넓이를 저장
		for (int i = 0; i < v.size(); ++i)
		{
			//스택에 저장된 높이와 벡터의 현재위치의 높이를 비교하여 현재 높이가 더 낮으면 현재 높이로부터 최대의 넓이를 구함
			while (!s.empty() && v[s.top()] >= v[i])
			{
				long long x = s.top();
				s.pop();
				long long width = (s.empty()) ? i : i - s.top() - 1;
				ret = max(ret, v[x] * width);
			}
			s.push(i);
		}
		cout << ret << '\n';
	}
	return 0;
}