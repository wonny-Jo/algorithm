#include<iostream>
using namespace std;

int main()
{
	long long X, Y, W, S;
	cin >> X >> Y >> W >> S;

	if (2 * W <= S) //대각선으로 가는것이 세로 한번 가로 한번 가는것보다 오래걸린다면 대각선은 갈필요없다.
		cout << (X + Y) * W;
	else //두번 이동보다 대각선이 이득인경우
	{
		if (W < S) //한번 이동보다 대각선이 더 걸리는경우
		{
			// 대각선으로 움직일수 있을만큼 움직이고 나머지는 한블록씩 이동
			if (X >= Y)
				cout << S * Y + W * (X - Y);
			else
				cout << S * X + W * (Y - X);
		}
		else //한번 이동보다 대각선이 이득인 경우
		{
			// 대각선으로 위와 같이 움직이고 남은 이동거리는 
			// 대각선으로 가능한 만큼 이동(2의 배수) 
			// 남은 거리가 있다면 한블록 이동
			if (X >= Y)
			{

				cout << S * Y + S * ((X - Y) / 2) * 2 + W * ((X - Y) % 2);
			}
			else
				cout << S * X + S * ((Y - X) / 2) * 2 + W * ((Y - X) % 2);
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}