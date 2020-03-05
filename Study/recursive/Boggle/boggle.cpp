#include<iostream>
#include<string>
using namespace std;
string block = {
	'U','R','L','P','M'
	,'X','P','R','E','T'
	,'G','I','A','E','T'
	,'X','T','N','Z','Y'
	,'X','O','Q','R','S'
};

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

bool isRange(int y, int x)
{
	if (y <= 0 || x <= 0 || y >= 5 || x >= 5)
		return false;
	return true;
}

bool hasWord(int y,int x, const string& word)
{
	//���� ���
	if (!isRange(y, x)) return false; //��� ���� �Ѿ�� false
	if (word[0] != block[5 * y + x]) return false;//ù���ڰ� Ʋ���� �ƿ�
	// else�� ���� ù�ܾ�� �������� ����
	if (word.size() == 1) return true;

	// �ֺ� 8���� ��� ���鼭 üũ
	for (int i = 0; i < 8; ++i)
	{
		if (hasWord(y + dy[i], x + dx[i], word.substr(1)))
			return true;
	}
	return false;
}


int main()
{
	int y, x;
	string word;
	cin >> y >> x >> word;
	cout<<hasWord(y, x, word);

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}