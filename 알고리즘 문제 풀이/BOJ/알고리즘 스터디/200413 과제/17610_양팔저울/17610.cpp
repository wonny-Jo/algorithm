#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool visit[3600000] = { 0 }; //������Ϳ� �ش� ���Ը� �־����� ����
int absol(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	vector<int> v;
	int k; cin >> k;
	int sum = 0; //��� ���� ������. �ᱹ Ž���� ������ ����
	for (int i = 0; i < k; ++i)
	{
		int a; cin >> a;
		v.push_back(a);
		sum += a;
	}


	visit[0] = 1; //���԰� 0�� �Ǵ� ��� ����
	vector<int> result; //������ ���Ը� ��Ƶ�.
	for (int i = 0; i < v.size(); ++i)
	{
		int cnt = 0;
		int size = result.size();
		while (!result.empty() && cnt < size)
		{
			int plus = v[i] + result[cnt];
			if (!visit[plus])
			{
				visit[plus] = 1;
				result.push_back(plus);
			}

			int minus = absol(v[i] - result[cnt]);
			if (!visit[minus])
			{
				visit[minus] = 1;
				result.push_back(minus);
			}
			++cnt;
		}
		if (!visit[v[i]])
		{
			result.push_back(v[i]);
			visit[v[i]] = 1;
		}
	}

	cout << sum - result.size();

	return 0;
}