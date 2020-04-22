#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int T; cin >> T;
	for (int a = 0; a < T; a++)
	{
		int n; cin >> n;
		int arr[100001];
		for (int i = 1; i <= n; i++) //���� ��ġ ����
			cin >> arr[i];
		bool visit[100001] = { 0 }; //�ش� ��ġ�� �湮�� ���� �ִ°�
		int ret[100001] = { 0 }; //��Ŭ �̷�� 1, �ƴϸ� -1
		for (int i = 1; i <= n; i++)
		{
			if (ret[i]==0) //���� ��Ŭ���� �ƴ��� �𸣴� ����
			{
				vector<int> v; //���������� ����� ������ ����
				v.push_back(i);
				visit[i] = 1;
				int next = arr[i];
				while (1)
				{
					if (visit[next]) 
					//���� ��ġ�� �̹� �湮�� ���� �ִٸ� ���� �ϳ�
					//1. ó������ ������ ��Ŭ
					//2. �߰����� ��Ŭ(�̹� �ϼ��� ��Ŭ�� �����ϴ� ��쵵 �ִ�.)
					{
						int ans = -1; //�ᱹ ������ ��ġ�� �����ϴ� ��ġ���� ��Ŭ�� �̷�� �� �������� ��Ŭ�� �̷��� ����.
						for (int i = 0; i < v.size(); i++)
						{
							if (v[i] == next)
								ans = 1;
							ret[v[i]] = ans;
						}
						break;
					}
					v.push_back(next);
					visit[next] = 1;
					next = arr[next];
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ret[i] == -1)
				++cnt;
		}
		cout << cnt << '\n';
	}

	return 0;
}