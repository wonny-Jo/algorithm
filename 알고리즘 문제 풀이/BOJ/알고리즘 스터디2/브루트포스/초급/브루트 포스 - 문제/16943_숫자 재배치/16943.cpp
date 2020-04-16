#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string A, B; cin >> A >> B;
	sort(A.begin(),A.end());
	int ANum = 0, BNum = 0;
	while (A[0] == '0')
		next_permutation(A.begin(), A.end());
	for (int i = 0; i < B.size(); i++)
	{
		BNum *=  10;
		BNum += B[i] - '0';
	}
	for (int i = 0; i < A.size(); i++)
	{
		ANum *= 10;
		ANum += A[i] - '0';
	}
	int min = BNum - ANum;
	if(min<0)
	{
		cout << -1;
		return 0;
	}
	int result = min;
	while (next_permutation(A.begin(),A.end()))
	{
		if (A[0] == '0')
			continue;
		ANum = 0;
		for (int i = 0; i < A.size(); i++)
		{
			ANum *= 10;
			ANum += A[i] - '0';
		}
		if (BNum - ANum < 0)
			break;
		result = ANum;
	}
	cout << result;
	return 0;
}
