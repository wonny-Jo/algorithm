#include<iostream>
using namespace std;
int INF = 100000;
int type[10][6] =
{
	(0,1,2,-1,-1),
	(3,7,9,11,-1),
	(4,10,14,15,-1),
	(0,4,5,6,7),
	(6,7,8,10,12),
	(0,2,14,15,-1),
	(3,14,15,-1,-1),
	(4,5,7,14,15),
	(1,2,3,4,5),
	(3,4,5,9,13)
};

int min(int a, int b)
{
	return (a < b) ? a : b;
}

// ��ü�� 12�ø� ����Ű���� Ȯ���ϴ� ����
// ->check�Լ��� �Ұ�

// �� ��ġ�� 3�ð��� type�� �°� ������ �Լ�
// ->rotation�Լ��� �Ұ�

bool check(int clock[17])
{
	for (int i = 0; i < 16; ++i)
	{
		if (clock[i] != 12)
			return false;
	}
	return true;
}

void rotation(int clock[17], int typeNum)
{
	for (int i = 0; i < 5; ++i)
	{
		if (type[typeNum][i] != -1)
		{
			clock[type[typeNum][i]] += 3;
			if (clock[type[typeNum][i]] == 15)
				clock[type[typeNum][i]] = 3;
		}
		else
			break;
	}
}

int solve(int clock[17],int typeNum)
{
	if (typeNum == 10)
		return check(clock) ? 0 : INF;

	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) //�̺κ� ������ ���ذ� �Ȱ�
	{
		ret = min(ret, cnt + solve(clock, typeNum + 1));
		rotation(clock, typeNum);
	}
	return ret;
}


int main()
{
	int C;
	cin >> C;
	for (int i = 0; i < C; ++i)
	{
		int clock[17] = { 0 };
		for (int j = 0; j < 16; ++j)
		{
			cin >> clock[j];
			int result = solve(clock,0);
			if (result >= INF)
				cout << -1 << endl;
			else
				cout << result << endl;
		}
	}
	return 0;
}