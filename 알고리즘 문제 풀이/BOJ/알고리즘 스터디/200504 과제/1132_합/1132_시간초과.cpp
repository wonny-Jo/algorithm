#include<iostream>
#include<algorithm>
using namespace std;
int N;
string s[51];
int alpha[10] = { 0,1,2,3,4,5,6,7,8,9 };

long long calcNum()
{
	long long ret = 0;
	for (int i = 0; i < N; i++)
	{
		long long num = 0;
		for (int j = 0; j < s[i].size(); j++)
		{
			num *= 10;
			num += alpha[s[i][j] - 'A'];
		}
		ret += num;
	}
	return ret;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i];

	long long ret = calcNum();
	while (next_permutation(alpha, alpha + 10))
		ret = max(ret, calcNum());
	cout << ret;
	return 0;
}
