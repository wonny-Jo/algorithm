#include<iostream>
#include<string>
using namespace std;

int hasMatching(int n,bool mask[11][11], bool areFriends[11]) 
//n은 학생수
//areFriends는 각 번호의 학생이 매칭이 되었는지 확인 true: 매칭, false: 노매칭
{
	// 짝이 모두 지어졌는지 확인
	int firstNum = -1; //매칭 안된 학생중 가장 빠른 번호 찾기
	for (int i = 0; i < n; ++i)
	{
		if (!areFriends[i]) {
			firstNum = i; break;
		}
	}
	if (firstNum==-1) return 1;

	int ret = 0;
	for (int i = firstNum+1; i < n; ++i) //i는 firstNum에 매칭되는 짝의 존재를 나타냄
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
		bool mask[11][11] = { 0 }; //친구가 될수있는 경우를 담음
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
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}