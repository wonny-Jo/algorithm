#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N, K; cin >> N >> K;
	string s;
	vector<int> size[21];
	for (int i = 0; i < N; ++i)//���� ����� ��ġ�� ������� ���Ϳ� ����
	{
		cin >> s;
		size[s.size()].push_back(i);
	}

	int ret = 0;
	for (int i = 0; i <= 20; ++i)//���ڼ�
	{
		if (size[i].empty())
			continue;

		queue<int> q;
		for (int j = 0; j < size[i].size(); ++j)
		{
			//���� ���� ��ġ�� ������ ����� ��ġ�� ���� K�̻� ���̳��� �͵��� ����
			while(!q.empty()&& size[i][j] - q.front() > K) 
				q.pop();
			ret += q.size(); //q�� ���� �͵��� ���� ������ ��ġ�� ���� �̷�� ����
			q.push(size[i][j]);
		}
	}
	cout << ret;
	return 0;
}