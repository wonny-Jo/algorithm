#include<iostream>
#include<string>
using namespace std;

int hasMatching(int n, bool mask[11][11], bool areFriends[11]) 
//n은 학생수
//areFriends는 각 번호의 학생이 매칭이 되었는지 확인 true: 매칭, false: 노매칭
{
	// 짝이 모두 지어졌는지 확인
	bool finish = true;
	for (int i = 0; i < n; ++i)
	{
		if (!areFriends[i]) finish = false;
	}
	if (finish) return 1;

	int ret = 0;
	for (int i = 0; i < n; ++i)	//(0,1)과 (1,0)을 다른 경우로 셈 //중복 문제
	//만약 mask도 양쪽 모두 체크했다면 {(0,1),(2,3)}과 {(2,3),(0,1)}을 다르게 보는 중복경우 추가발생
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
		bool mask[11][11] = { 0 }; //친구가 될수있는 경우를 담음
		cin >> n >> m;
		for (int j = 0; j < m; ++j)
		{
			cin >> num[0] >> num[1];
			mask[num[0]][num[1]] = 1;
		}
		bool areFriends[11] = { false };
		cout << hasMatching(n, mask, areFriends)<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}