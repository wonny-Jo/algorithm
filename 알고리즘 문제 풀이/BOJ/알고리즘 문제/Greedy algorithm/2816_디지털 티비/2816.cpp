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
		if (strcmp(channelName, "KBS1") == 0)	//KBS1�� ��ġ �ľ�
			KBS1_start_pos = i;
		else if (strcmp(channelName, "KBS2") == 0) //KBS2�� ��ġ �ľ�
			KBS2_start_pos = i;
	}

	//KBS1 ���� �ű��
	for (int j = 1; j < KBS1_start_pos; ++j)
		cout << '1';
	for (int j = 1; j < KBS1_start_pos; ++j)
		cout << '4';

	//KBS2 �ű��
	if (KBS1_start_pos > KBS2_start_pos) //KBS2�� ���� �־����� KBS1 �ű涧 �ϳ� �ö�
		++KBS2_start_pos;
	for (int j = 1; j < KBS2_start_pos; ++j)
		cout << '1';
	for (int j = 2; j < KBS2_start_pos; ++j)
		cout << '4';
	
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}