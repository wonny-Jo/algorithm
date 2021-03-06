#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	char channelName[20];
	int KBS1_start_pos = 0, KBS2_start_pos = 0;
	int channel_pos=0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> channelName;
		if (strcmp(channelName, "KBS1") == 0)	//KBS1의 위치 파악
			KBS1_start_pos = i;
		else if (strcmp(channelName, "KBS2") == 0) //KBS2의 위치 파악
			KBS2_start_pos = i;
	}

	//KBS1 먼저 옮기기
	for (int j = 1; j < KBS1_start_pos; ++j)
		cout << '1';
	for (int j = 1; j < KBS1_start_pos; ++j)
		cout << '4';

	//KBS2 옮기기
	if (KBS1_start_pos > KBS2_start_pos) //KBS2가 위에 있었으면 KBS1 옮길때 하나 올라감
		++KBS2_start_pos;
	for (int j = 1; j < KBS2_start_pos; ++j)
		cout << '1';
	for (int j = 2; j < KBS2_start_pos; ++j)
		cout << '4';
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}