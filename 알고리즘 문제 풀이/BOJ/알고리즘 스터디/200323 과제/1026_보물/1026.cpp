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
	sort(A, A + N); //A는 오름차순
	int S = 0;

	//B는 맥스값과 위치를 찾아서 A의 왼쪽부터 곱해주고 더해줌
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