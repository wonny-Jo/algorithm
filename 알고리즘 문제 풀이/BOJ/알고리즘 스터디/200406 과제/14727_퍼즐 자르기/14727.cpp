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

	stack<long long> s; //������׷� ��ġ ����
	long long ret = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		//���� ����� ��ġ �� �ֱٿ� ����� ���� ���̰� v[i]���� ũ��
		//�� ���̸� ���������� �簢���� ��� ����.
		while (!s.empty() && v[s.top()] >= v[i])
		{
			long long j = s.top();
			s.pop();
			long long width;
			//s�� ������ ���ٸ� �������� ���̴� ���� i�� ���̰� �ȴ�.
			if (s.empty())
				width = i;
			//s�� ������ �ִٸ� �� ��ġ�� ���� ������ ������ ���̴�.
			else
				width = i - s.top() - 1;
			ret = max(ret, v[j] * width);
		}
		s.push(i);
	}
	cout << ret;
	return 0;
}