#include<iostream>
#include<stack>
using namespace std;

string oper("+-*/()");

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	string s;
	cin >> s;
	
	string result;
	stack<char> sta;
	for (int i = 0; i < s.size(); ++i)
	{
		//��ȣ�� �������� �ڱ⺸�� �켱������ ���ų� ������ ��
		if (oper.find(s[i]) != -1) //�������̸�
		{
			if (s[i]=='(') //���� �켱�����̹Ƿ� �־��
				sta.push(s[i]);
			else if (s[i] == '*' || s[i] == '/') //
			{
				while (!sta.empty() && (sta.top() == '*' || sta.top() == '/'))
				{
					result += sta.top();
					sta.pop();
				}
				sta.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!sta.empty() && sta.top() != '(')
				{
					result += sta.top();
					sta.pop();
				}
				sta.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!sta.empty() && sta.top() != '(')
				{
					result += sta.top();
					sta.pop();
				}
				sta.pop();
			}
		}
		else //�ǿ����� �߰�
			result += s[i];
		
	}

	while (!sta.empty())
	{
		result += sta.top();
		sta.pop();
	}

	cout << result << endl;
	return 0;
}