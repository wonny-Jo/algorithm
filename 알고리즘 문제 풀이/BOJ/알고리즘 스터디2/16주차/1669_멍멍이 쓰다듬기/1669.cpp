#include<iostream>
using namespace std;
int X, Y;

//1- 1			=1��
//2 - 2			=1��
//3~4 - 3		=2��
//5~6 - 4		=2��
//7~9 - 5		=3��
//10~12 - 6		=3��


int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> X >> Y;
	int dist = Y - X;

	int ret = 0;
	int cnt = 0, num = 1;
	while (dist > 0)
	{
		dist -= num;
		++cnt;
		if (cnt == 2)
		{
			cnt = 0;
			++num;
		}
		++ret;
	}
	cout << ret;
	return 0;
}
