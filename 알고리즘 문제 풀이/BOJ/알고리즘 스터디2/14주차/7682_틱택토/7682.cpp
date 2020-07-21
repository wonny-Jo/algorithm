#include<iostream>
#include<string>
using namespace std;
char block[3][3];

//**��ĭ�� �ִ��� üũ**
//��ĭ�� �ִ� ��� : �ºΰ� ������. 2���̻��� ���� �ȵ� 
// - x�� �̱��� (x�� ����== o�� ����+1) // o�� �̱��� (x�� ����== o�� ����) 
//��ĭ�� ���� ���  //x�� ����=5, o�� ����=4
// - �ºΰ� �� ���. ������ x�� ��. 2�� �̻��̳��� �ȵ�
// - �ºΰ� ���� ���� ���. ���� �������.
bool check()
{
	bool hasBlank = false;
	int xCnt = 0, oCnt = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (block[i][j] == '.')
				hasBlank = true;
			else if (block[i][j] == 'X')
				++xCnt;
			else if (block[i][j] == 'O')
				++oCnt;
		}

	int xLine = 0, oLine = 0;
	//������ 8���� ���
	//������*3
	for (int i = 0; i < 3; i++)
	{
		if (block[i][0] == block[i][1] && block[i][1] == block[i][2])
		{
			if (block[i][0] == 'X')
				++xLine;
			else if (block[i][0] == 'O')
				++oLine;
		}
	}
	//��
	//��*3
	//��
	for (int i = 0; i < 3; i++)
	{
		if (block[0][i] == block[1][i] && block[1][i] == block[2][i])
		{
			if (block[0][i] == 'X')
				++xLine;
			else if (block[0][i] == 'O')
				++oLine;
		}
	}
	//��
	// ��
	//  ��
	if (block[0][0] == block[1][1] && block[1][1] == block[2][2])
	{
		if (block[1][1] == 'X')
			++xLine;
		else if (block[1][1] == 'O')
			++oLine;
	}
	//  ��
	// ��
	//��
	if (block[0][2] == block[1][1] && block[1][1] == block[2][0])
	{
		if (block[1][1] == 'X')
			++xLine;
		else if (block[1][1] == 'O')
			++oLine;
	}

	if (hasBlank) //��ĭ�� �ִ°��
	{
		if (xLine >= 1 && oLine == 0 && xCnt == oCnt + 1)
			return true;
		if (xLine == 0 && oLine >= 1 && xCnt == oCnt)
			return true;
	}
	else //��ĭ�� ���°��
	{
		//�ºΰ� �� ���
		if (xLine >= 1 && oLine == 0 && xCnt == oCnt + 1)
			return true;
		if (xLine == 0 && oLine == 0 && xCnt == oCnt + 1)
			return true;
	}
	return false;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	while (1)
	{
		cin >> s;
		if (s == "end")
			break;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				block[i][j] = s[i * 3 + j];

		if (check())
			cout << "valid" << '\n';
		else
			cout << "invalid" << '\n';
	}
	return 0;
}