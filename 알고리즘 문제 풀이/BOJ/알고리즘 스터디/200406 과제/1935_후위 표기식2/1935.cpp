#include<iostream>
#include<stack>
using namespace std;
string operation("+-*/");

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N; cin >> N;
	string s; cin >> s;
	double arr[26];
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	
	stack<double> num;
	int size = s.size();
	for (int i = 0; i < size; ++i)
	{
		if (operation.find(s[i]) == -1)
			num.push(arr[s[i] - 'A']);
		else
		{
			double b = num.top();
			num.pop();
			double a = num.top();
			num.pop();
			if (s[i] == '+')
				num.push(a + b);
			else if (s[i] == '-')
				num.push(a - b);
			else if (s[i] == '*')
				num.push(a * b);
			else if (s[i] == '/')
				num.push(a / b);
		}
	}
	cout.precision(2);
	cout << fixed << num.top();
	return 0;
}