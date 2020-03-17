#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	int A[51], B[51];
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i)
		cin >> B[i];
	sort(A, A + N); //A�� ��������
	int S = 0;

	//B�� �ƽ����� ��ġ�� ã�Ƽ� A�� ���ʺ��� �����ְ� ������
	bool isMax[51] = { 0 };
	for (int i = 0; i < N; ++i)
	{
		int max = 0;
		int max_pos = 0;
		for (int j = 0; j < N; ++j)
		{
			if (isMax[j] == 0 && max < B[j])
			{
				max = B[j];
				max_pos = j;
			}
		}
		S += max * A[i];
		isMax[max_pos] = 1;
	}
	cout << S;
	return 0;
}