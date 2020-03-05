#include<iostream>
using namespace std;

int main()
{
	int N, S, R;
	cin >> N >> S >> R;
	bool broken[11] = { 0 }, remain[11] = { 0 }; //broken�� �ջ�� ��ġ remain�� ������ġ
	
	//�ջ�� ���� ������ �� ����. ���� ���� �ڽŵ� �����ִ°����� ����.
	int num;
	for (int i = 0; i < S; ++i)
	{
		cin >> num; broken[num] = 1;
	}
	for (int i = 0; i < R; ++i)
	{
		cin >> num;
		if (broken[num] == 1)
		{
			broken[num] = 0;
			--S;
		}
		else
			remain[num] = 1;
	}
	//�������� üũ�Ͽ� �ջ�� �켱������ �����ش�.
	for (int i = 1; i <= N; ++i)
	{
		if (remain[i] == 1)
		{
			if (broken[i - 1] == 1)
			{
				broken[i - 1] = 0;
				--S;
			}
			else if (broken[i + 1] == 1) 
			{
				broken[i + 1] = 0;
				--S;
			}
		}
	}
	cout << S;

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}