#include<iostream>
using namespace std;

int main()
{
	int N, M, K, result;
	cin >> N >> M >> K;
	if (K == 0) // 인턴쉽 학생이 0명일 경우 예외처리
	{
		result = (N > 2 * M) ? M : N / 2;
	}
	else
	{
		if (N % 2 == 1) //여학생수를 짝수로 만들기
		{
			--N; --K;
		}
		K -= (N > 2 * M) ? (N - 2 * M) : ((2 * M - N) / 2);// N=2M을 만드는 작업 // 코드 상에는 K만 조절
		if (K < 0) K = 0; //K가 0보다 작을때의 예외처리
		result = (N > 2 * M) ? (M - K / 3) : (N / 2 - K / 3);
		if (K % 3 != 0)	--result;
	}
	cout << result;
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}