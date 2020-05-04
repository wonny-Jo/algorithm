#include<iostream>
using namespace std;
string v[1001];

string print(string s)
{
	string ret = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1') ret += '(';
		else if (s[i] == '2') ret += ')';
		else if (s[i] == '3') ret += '{';
		else if (s[i] == '4') ret += '}';
		else if (s[i] == '5') ret += '[';
		else if (s[i] == '6') ret += ']';
	}
	return ret;
}

string plusNum(string a,string b)
{
	return a + b < b + a ? a + b : b + a;
}

string multiplyNum(string a, int type) //type 2,3,5
{
	string ret = "";
	if (type == 2)
	{
		ret += '1'; ret += a; ret += '2';
	}
	if (type == 3)
	{
		ret += '3'; ret += a; ret += '4';
	}
	if (type == 5)
	{
		ret += '5'; ret += a; ret += '6';
	}
	return ret;
}

string findMin(string a, string b)
{
	if (a.size() < b.size())
		return a;
	else if (a.size() > b.size())
		return b;
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i])
				continue;
			else if (a[i] < b[i])
				return a;
			else
				return b;
		}
	}
	return a;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	v[0] = ""; v[1] = "12"; v[2] = "34"; v[3] = "56";
	for (int i = 4; i <= 1000; i++)
	{
		v[i] = plusNum(v[1], v[i - 1]); //+1
		for (int j = 2; j <= i/2; j++)
			v[i] = findMin(v[i], plusNum(v[j], v[i - j]));
		if (i % 2 == 0) v[i] = findMin(v[i], multiplyNum(v[i / 2], 2)); //*2
		if (i % 3 == 0) v[i] = findMin(v[i], multiplyNum(v[i / 3], 3)); //*3
		if (i % 5 == 0) v[i] = findMin(v[i], multiplyNum(v[i / 5], 5)); //*5
	}

	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N; cin >> N;
		cout << print(v[N]) << '\n';
	}

	return 0;
}
