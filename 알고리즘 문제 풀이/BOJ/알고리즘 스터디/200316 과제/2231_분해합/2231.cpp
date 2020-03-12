#include<iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	int result = 0; //생성자 없으면 0

	//그냥 처음부터 N까지 돌면서 확인
	for (int i = 1; i < N; ++i)
	{
		int sum = i,temp = i;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == N)
		{
			result = i;
			break;
		}
	}
	cout << result;
	return 0;
}