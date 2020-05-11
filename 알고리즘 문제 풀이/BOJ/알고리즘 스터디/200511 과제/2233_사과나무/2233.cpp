#include<iostream>
using namespace std;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int N; cin >> N;
	int par[2001]; //각 idx의 부모의 위치 저장
	int pos[2001][2]; //각 idx의 시작과 끝 방문 위치
	string s; cin >> s;
	int parent = -1;
	int idx = 0;
	int del[2]; cin >> del[0] >> del[1];
	int posApple[2];

	//각 idx별로 부모의 위치와 방문 시작 끝 위치를 저장한다.
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			pos[idx][0] = i + 1;
			par[idx] = parent;
			parent = idx;
			idx++;
		}
		else
		{
			pos[parent][1] = i + 1;
			parent = par[parent];
		}

		//썩은 두 사과의 idx찾기
		if (i == del[0] - 1)
			posApple[0] = idx - 1;
		if (i == del[1] - 1)
			posApple[1] = idx - 1;
	}

	//두 썩은 사과의 공통 부모 찾기
	while (posApple[0] != posApple[1])
	{
		if (posApple[0] > posApple[1])
			posApple[0] = par[posApple[0]];
		else
			posApple[1] = par[posApple[1]];
	}

	//공통 부모의 시작과 끝 위치 출력
	int posPar = posApple[0];
	cout << pos[posPar][0] << ' ' << pos[posPar][1];

	return 0;
}