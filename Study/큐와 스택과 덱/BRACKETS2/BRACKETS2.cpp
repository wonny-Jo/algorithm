#include<iostream>
#include<stack>
using namespace std;

bool wellMatched(const string& formula)
{
	// ���� ��ȣ ���ڵ�� �ݴ� ��ȣ ���ڵ�
	const string opening("({["), closing(")}]");
	//�̹� ���� ��ȣ���� ������� ��� ����
	stack<char> openStack;
	for (int i = 0; i < formula.size(); ++i)
	{
		if (opening.find(formula[i]) != -1)
			//���� ��ȣ��� ������ ���ÿ� �ִ´�.
			openStack.push(formula[i]);
		else
		{
			//�̿��� ��� ���� ������ ���ڿ� ������
			//������ ����ִ� ��쿡�� ����
			if (openStack.empty()) return false;
			//���� ���� �ʴ� ��쵵 ����
			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			//¦�� �������� ���ÿ��� ����
			openStack.pop();
		}
	}
	//���ÿ� ������ ���� ��ȣ�� ����� ����
	return openStack.empty();
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int C; cin >> C;
	for (int i = 0; i < C; ++i)
	{
		string s; cin >> s;
		if (wellMatched(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}