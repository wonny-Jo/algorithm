#include<iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	string number;
	cin >> number;
	int remain = N-K;
	int pos = 0, prePos;
	while (remain>0)
	{
		char max = '0';
		prePos = pos;
		for (int i = prePos; i < N-remain+1; ++i)
		{
			if (max < number[i])
			{
				max = number[i];
				pos = i;
			}
		}
		cout << max;
		--remain;
		++pos;
	}

	return 0;
}