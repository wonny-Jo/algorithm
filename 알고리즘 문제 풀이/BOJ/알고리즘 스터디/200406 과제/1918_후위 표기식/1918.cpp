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
		//기호가 나왔을때 자기보다 우선순위가 높거나 같으면 팝
		if (oper.find(s[i]) != -1) //연산자이면
		{
			if (s[i]=='(') //제일 우선순위이므로 넣어둠
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
		else //피연산자 추가
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