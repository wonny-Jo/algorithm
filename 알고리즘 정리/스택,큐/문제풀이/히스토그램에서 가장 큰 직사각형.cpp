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
		vector<long long> v; //���̸� ������� ����
		for (int i = 0; i < N; ++i)
		{
			long long a; cin >> a;
			v.push_back(a);
		}
		v.push_back(0); //�������� ���ÿ� ������������ ���� �͵鿡�� �ִ���̸� ���ϱ����ؼ� �־���

		stack<long long> s; //������ ������ġ���� �� �������� ������ ���� ������ġ���� ����
		long long ret = 0; //���� ���� ���簢���� ���̸� ����
		for (int i = 0; i < v.size(); ++i)
		{
			//���ÿ� ����� ���̿� ������ ������ġ�� ���̸� ���Ͽ� ���� ���̰� �� ������ ���� ���̷κ��� �ִ��� ���̸� ����
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