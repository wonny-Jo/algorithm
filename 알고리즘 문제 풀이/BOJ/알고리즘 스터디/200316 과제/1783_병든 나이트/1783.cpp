#include<iostream>
using namespace std;

//이동 방법은 4가지 
//int move[4][2] = { {-2,1},{-1,2},{1,2},{2,1} };

int numOfVisit(int N, int M)
{
	//세로의 길이가 1이면 이동할수 없다.
	if (N == 1)
		return 1;

	//세로의 길이가 2면 이동수단은 2,3번만 가능하다.
	//2,3번의 움직임은 오른쪽으로 2칸씩 이동함.
	if (N == 2)
	{
		//모든 이동수단을 다 사용할 수 없으므로 최대값은 4이다.
		if (M >= 7)
			return 4;
		else
			return (M+1) / 2;
	}

	//if(N>=3)
	if (1 <= M && M <= 4) //오른쪽으로 한칸씩 이동 가능한 경우
		return M;
	if (5 <= M && M <= 6) //오른쪽으로 두칸 이동이 한번 들어간경우
		return 4;
	if (M >= 7)
	{
		//M이 7까지는 4가지 모두 사용해야하므로 5칸방문.
		//남은 가로의 칸들은 한칸씩 가면된다.
		return 5 + (M - 7);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	cout << numOfVisit(N, M);
	
	return 0;
}