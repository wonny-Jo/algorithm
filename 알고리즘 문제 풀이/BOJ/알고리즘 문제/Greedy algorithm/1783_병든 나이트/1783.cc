#include<iostream>
using namespace std;

int main()
{
	long long N, M;
	cin >> N >> M;
	long long result = 1;
	M -= 1; //처음위치는 없앰
	//if(N == 1) 이동못함
	if (N == 2) //2,3번 동작밖에 못함(오른쪽으로 2칸씩 가는경우만 가능)
	{
		if (M >= 6)	//4번갈려면 모든 경우 다 사용해야하므로 3번이 최대
			result += 3;
		else
			result += M / 2;
	}
	else if (N > 2) //모든 동작 가능
	{
		if (M < 6) //이동 거리가 6보다 작으면 1,1,1의 순서로 세번이 최선
		{
			for (int i = 0; i < 3; ++i)
			{
				if (M > 0)
				{
					++result; --M;
				}
			}
		}
		else 
		{
			M -= 6; result += 4;//처음에 4가지 경우는 다 써야함
			result += M;
		}
	}
	cout << result;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}