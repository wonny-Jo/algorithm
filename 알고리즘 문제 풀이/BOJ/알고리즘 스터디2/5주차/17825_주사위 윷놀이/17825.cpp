#include<iostream>
#include<algorithm>
using namespace std;
int route[4][22] = { 
	{ 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0 }, //일반route
	{ -1,13,16,19,25,30,35,40,0 }, //hidden route 1
	{ -2,22,24,25,30,35,40,0 }, //hidden route 2
	{ -3,28,27,26,25,30,35,40,0 } //hidden route 3
};
int diceNum[10]; //10개의 주사위 숫자

int sumPoint(int n)
{
	int num = n;

	//말은 0,1,2,3
	int horse;
	int hidden[4] = { 0 };//말이 파란색지역으로 들어가는지 체크//0이 route, 1,2,3은 hidden
	int pos[4] = { 0 }; //해당 루트에서의 말의 위치
	int sum = 0; //점수의 합계
	bool goal[4] = { 0 }; //각 말이 도착했는지 체크
	for (int i = 0; i < 10; i++)
	{
		horse=num % 4;
		num /= 4;
		if (goal[horse])
			return 0;

		pos[horse] += diceNum[i];
		if (hidden[horse] == 0) //route에서
		{
			if (pos[horse] >= 21)
			{
				goal[horse] = 1;
				continue;
			}
			sum += route[hidden[horse]][pos[horse]];
			if (pos[horse] % 5 == 0 && pos[horse] / 5 != 4) //hidden route로 들어가는지 체크
			{
				hidden[horse] = pos[horse] / 5;
				pos[horse] = 0;
			}
		}
		else if (hidden[horse] == 1)
		{
			if (pos[horse] >= 8)
			{
				goal[horse] = 1;
				continue;
			}
			sum += route[hidden[horse]][pos[horse]];
		}
		else if (hidden[horse] == 2)
		{
			if (pos[horse] >= 7)
			{
				goal[horse] = 1;
				continue;
			}
			sum += route[hidden[horse]][pos[horse]];
		}
		else if (hidden[horse] == 3)
		{
			if (pos[horse] >= 8)
			{
				goal[horse] = 1;
				continue;
			}
			sum += route[hidden[horse]][pos[horse]];
		}

		//위치가 겹치는 경우가 발생하면 안되므로 예외처리
		//좀 복잡...
		for (int j = 0; j < 3; j++)
		{
			for (int k = j + 1; k < 4; k++)
			{
				if ((pos[j] > 0 || hidden[j] != 0) && !goal[j]) //시작지점, 끝지점에서 겹치는 경우가 아닌 경우
				{
					//두 말의 이동 경로가 같은경우
					if (hidden[j] == hidden[k] && pos[j] == pos[k])
						return 0;

					//두말의 이동경로는 다르지만 겹치는 경우
					if (hidden[j] != hidden[k])
					{
						//겹치는 곳은 25,30,35,40뿐. 
						//두 말의 경로중 하나가 0인경우, 0의 경로로 들어가는 경우는 40뿐
						if ((hidden[j]==0||hidden[k]==0)&&
							route[hidden[j]][pos[j]] == route[hidden[k]][pos[k]] &&
							(route[hidden[j]][pos[j]] == 40))
							return 0;

						//두 말의 경로가 모두 0이 아닌경우에는 25,30,35,40이 겹침 포인트 //경로의 시작위치를 -처리함으로써 30은 추가적인 고려 x
						if ((hidden[j] != 0 && hidden[k] != 0) && 
							route[hidden[j]][pos[j]] == route[hidden[k]][pos[k]])
							return 0;
					}
					
				}
			}
		}
	}

	return sum;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	for (int i = 0; i < 10; i++)
		cin >> diceNum[i];

	int ret = 0;
	for (int i = 0; i < 1<<20; i++)
		ret = max(ret, sumPoint(i));
	cout << ret;

	return 0;
}