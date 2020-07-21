#include<iostream>
#include<string>
using namespace std;
char block[3][3];

//**빈칸이 있는지 체크**
//빈칸이 있는 경우 : 승부가 나야함. 2줄이상이 나면 안됨 
// - x가 이긴경우 (x의 개수== o의 개수+1) // o가 이긴경우 (x의 개수== o의 개수) 
//빈칸이 없는 경우  //x의 개수=5, o의 개수=4
// - 승부가 난 경우. 무조건 x의 승. 2줄 이상이나면 안됨
// - 승부가 나지 않은 경우. 줄이 없어야함.
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
	//라인은 8가지 경우
	//ㅁㅁㅁ*3
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
	//ㅁ
	//ㅁ*3
	//ㅁ
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
	//ㅁ
	// ㅁ
	//  ㅁ
	if (block[0][0] == block[1][1] && block[1][1] == block[2][2])
	{
		if (block[1][1] == 'X')
			++xLine;
		else if (block[1][1] == 'O')
			++oLine;
	}
	//  ㅁ
	// ㅁ
	//ㅁ
	if (block[0][2] == block[1][1] && block[1][1] == block[2][0])
	{
		if (block[1][1] == 'X')
			++xLine;
		else if (block[1][1] == 'O')
			++oLine;
	}

	if (hasBlank) //빈칸이 있는경우
	{
		if (xLine >= 1 && oLine == 0 && xCnt == oCnt + 1)
			return true;
		if (xLine == 0 && oLine >= 1 && xCnt == oCnt)
			return true;
	}
	else //빈칸이 없는경우
	{
		//승부가 난 경우
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