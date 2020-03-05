#include<iostream>
#include<string>
using namespace std;

int hasMatching(int n, bool mask[11][11], bool areFriends[11]) 
//n�� �л���
//areFriends�� �� ��ȣ�� �л��� ��Ī�� �Ǿ����� Ȯ�� true: ��Ī, false: ���Ī
{
	// ¦�� ��� ���������� Ȯ��
	bool finish = true;
	for (int i = 0; i < n; ++i)
	{
		if (!areFriends[i]) finish = false;
	}
	if (finish) return 1;

	int ret = 0;
	for (int i = 0; i < n; ++i)	//(0,1)�� (1,0)�� �ٸ� ���� �� //�ߺ� ����
	//���� mask�� ���� ��� üũ�ߴٸ� {(0,1),(2,3)}�� {(2,3),(0,1)}�� �ٸ��� ���� �ߺ���� �߰��߻�
	{
		for (int j = 0; j < n; ++j)
		{
			if (!areFriends[i] && !areFriends[j] && mask[i][j])
			{
				areFriends[i] = true; areFriends[j] = true;
				ret += hasMatching(n, mask, areFriends);
				areFriends[i] = false; areFriends[j] = false;
			}
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
		}
		bool areFriends[11] = { false };
		cout << hasMatching(n, mask, areFriends)<<endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}