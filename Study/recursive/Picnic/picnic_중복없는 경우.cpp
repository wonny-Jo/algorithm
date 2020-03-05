#include<iostream>
#include<string>
using namespace std;

int hasMatching(int n,bool mask[11][11], bool areFriends[11]) 
//n�� �л���
//areFriends�� �� ��ȣ�� �л��� ��Ī�� �Ǿ����� Ȯ�� true: ��Ī, false: ���Ī
{
	// ¦�� ��� ���������� Ȯ��
	int firstNum = -1; //��Ī �ȵ� �л��� ���� ���� ��ȣ ã��
	for (int i = 0; i < n; ++i)
	{
		if (!areFriends[i]) {
			firstNum = i; break;
		}
	}
	if (firstNum==-1) return 1;

	int ret = 0;
	for (int i = firstNum+1; i < n; ++i) //i�� firstNum�� ��Ī�Ǵ� ¦�� ���縦 ��Ÿ��
	{
		if (!areFriends[firstNum] && !areFriends[i] && mask[firstNum][i])
		{
			areFriends[i] = true; areFriends[firstNum] = true;
			ret += hasMatching(n,mask,areFriends);
			areFriends[i] = false; areFriends[firstNum] = false;
		}
	}
	return ret;
}
int main()
{
	int C;
	cin >> C;
	int n, m;
	int num[2];
	for (int i = 1; i <= C; ++i)
	{
		bool mask[11][11] = { 0 }; //ģ���� �ɼ��ִ� ��츦 ����
		cin >> n >> m;
		for (int j = 0; j < m; ++j)
		{
			cin >> num[0] >> num[1];
			mask[num[0]][num[1]] = 1;
			mask[num[1]][num[0]] = 1;
		}
		bool areFriends[11] = { false };
		cout << hasMatching(n,mask, areFriends)<<endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}