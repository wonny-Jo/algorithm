#include<iostream>
#include<algorithm>
using namespace std;
int route[4][22] = { 
	{ 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0 }, //�Ϲ�route
	{ -1,13,16,19,25,30,35,40,0 }, //hidden route 1
	{ -2,22,24,25,30,35,40,0 }, //hidden route 2
	{ -3,28,27,26,25,30,35,40,0 } //hidden route 3
};
int diceNum[10]; //10���� �ֻ��� ����

int sumPoint(int n)
{
	int num = n;

	//���� 0,1,2,3
	int horse;
	int hidden[4] = { 0 };//���� �Ķ����������� ������ üũ//0�� route, 1,2,3�� hidden
	int pos[4] = { 0 }; //�ش� ��Ʈ������ ���� ��ġ
	int sum = 0; //������ �հ�
	bool goal[4] = { 0 }; //�� ���� �����ߴ��� üũ
	for (int i = 0; i < 10; i++)
	{
		horse=num % 4;
		num /= 4;
		if (goal[horse])
			return 0;

		pos[horse] += diceNum[i];
		if (hidden[horse] == 0) //route����
		{
			if (pos[horse] >= 21)
			{
				goal[horse] = 1;
				continue;
			}
			sum += route[hidden[horse]][pos[horse]];
			if (pos[horse] % 5 == 0 && pos[horse] / 5 != 4) //hidden route�� ������ üũ
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

		//��ġ�� ��ġ�� ��찡 �߻��ϸ� �ȵǹǷ� ����ó��
		//�� ����...
		for (int j = 0; j < 3; j++)
		{
			for (int k = j + 1; k < 4; k++)
			{
				if ((pos[j] > 0 || hidden[j] != 0) && !goal[j]) //��������, ���������� ��ġ�� ��찡 �ƴ� ���
				{
					//�� ���� �̵� ��ΰ� �������
					if (hidden[j] == hidden[k] && pos[j] == pos[k])
						return 0;

					//�θ��� �̵���δ� �ٸ����� ��ġ�� ���
					if (hidden[j] != hidden[k])
					{
						//��ġ�� ���� 25,30,35,40��. 
						//�� ���� ����� �ϳ��� 0�ΰ��, 0�� ��η� ���� ���� 40��
						if ((hidden[j]==0||hidden[k]==0)&&
							route[hidden[j]][pos[j]] == route[hidden[k]][pos[k]] &&
							(route[hidden[j]][pos[j]] == 40))
							return 0;

						//�� ���� ��ΰ� ��� 0�� �ƴѰ�쿡�� 25,30,35,40�� ��ħ ����Ʈ //����� ������ġ�� -ó�������ν� 30�� �߰����� ��� x
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