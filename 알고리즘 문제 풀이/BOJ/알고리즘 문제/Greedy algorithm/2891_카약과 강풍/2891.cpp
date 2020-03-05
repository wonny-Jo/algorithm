#include<iostream>
using namespace std;

int main()
{
	int N, S, R;
	cin >> N >> S >> R;
	bool broken[11] = { 0 }, remain[11] = { 0 }; //broken은 손상된 위치 remain은 여분위치
	
	//손상된 팀과 여분의 팀 세팅. 여분 팀은 자신도 갈수있는경우까지 세팅.
	int num;
	for (int i = 0; i < S; ++i)
	{
		cin >> num; broken[num] = 1;
	}
	for (int i = 0; i < R; ++i)
	{
		cin >> num;
		if (broken[num] == 1)
		{
			broken[num] = 0;
			--S;
		}
		else
			remain[num] = 1;
	}
	//여분팀을 체크하여 앞사람 우선순위로 빌려준다.
	for (int i = 1; i <= N; ++i)
	{
		if (remain[i] == 1)
		{
			if (broken[i - 1] == 1)
			{
				broken[i - 1] = 0;
				--S;
			}
			else if (broken[i + 1] == 1) 
			{
				broken[i + 1] = 0;
				--S;
			}
		}
	}
	cout << S;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}