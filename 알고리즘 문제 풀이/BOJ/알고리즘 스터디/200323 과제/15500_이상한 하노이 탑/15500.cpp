#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void print(vector<pair<int, int>> v)
{
	int size = v.size();
	cout << size << '\n';
	for (int i = 0; i < size; ++i)
		cout << v[i].first << ' ' << v[i].second << '\n';
}
int main()
{
	int N;
	cin >> N;
	int arr[124] = { 0 }; //�� ������ ��� ����Ǿ��ִ��� ��Ÿ���� �迭
	int a;
	vector<pair<int, int>> v;//�������� ������ ����
	stack<int> s[4]; //�� ��ġ�� ������ ����

	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		arr[a] = 1;
		s[1].push(a);
	}

	//���̵�� : ���� ū ���� ã�Ƽ� 3���� ������� �ű���
	//���� ���� ū ���� �ƴ϶�� �ٸ� ������ �ű���
	//ex) 1�� ��ġ�� �־����� 2��, 2�� ��ġ�� �־����� 1�� �ű�
	while (N>0)
	{
		if (arr[N] == 1)
		{
			if (s[1].top() == N)
			{
				v.push_back({ 1,3 });
				s[3].push(s[1].top());
				s[1].pop();
				arr[N] = 3;
				--N;
			}
			else
			{
				v.push_back({ 1,2 });
				s[2].push(s[1].top());
				s[1].pop();
				arr[s[2].top()] = 2;
			}
		}
		else if (arr[N] == 2)
		{
			if (s[2].top() == N)
			{
				v.push_back({ 2,3 });
				s[3].push(s[2].top());
				s[2].pop();
				arr[N] = 3;
				--N;
			}
			else
			{
				v.push_back({ 2,1 });
				s[1].push(s[2].top());
				s[2].pop();
				arr[s[1].top()] = 1;
			}
		}
	}

	print(v);

	return 0;
}