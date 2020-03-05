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
	//기저 사례
	if (!isRange(y, x)) return false; //블록 범위 넘어가면 false
	if (word[0] != block[5 * y + x]) return false;//첫글자가 틀리면 아웃
	// else의 경우는 첫단어는 성공으로 간주
	if (word.size() == 1) return true;

	// 주변 8가지 경우 돌면서 체크
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

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}