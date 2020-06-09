#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int N, M;
int A[501], B[501];
int dp[501][501];
pair<int,int> nextPos[501][501];

int dfs(int A_pos, int B_pos)
{
	int& ret = dp[A_pos][B_pos];
	if (ret != -1)
		return ret;

	if (A_pos == N || B_pos == M)
		return 0;

	ret = 1;
	for (int i = A_pos + 1; i < N; i++)
	{
		if (A[A_pos] >= A[i]) // ���� ��ġ ���Ŀ� �����鼭 ���纸�� ū ���� ã��
			continue;
		for (int j = B_pos + 1; j < M; j++)
		{
			if (A[i] == B[j])
			{
				int temp = dfs(i, j);
				if (ret <= temp) //���̰� �ִ��ΰ� ã��
				{
					ret = temp + 1;//�ִ� ����
					nextPos[A_pos][B_pos] = { i,j }; //���� ��ġ ����
				}
				break;
			}
		}
	}
	return ret;
}

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> B[i];
	memset(nextPos, -1, sizeof(nextPos));
	memset(dp, -1, sizeof(dp));
	pair<int, int> cur = { -1,-1 };
	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (A[i] == B[j])
			{
				int temp = dfs(i, j);
				if (ret < temp)
				{
					ret = temp;
					cur = { i, j }; //ó�� ��ġ ����
				}
				break;
			}
	cout << ret << '\n';
	while (cur.first != -1 && cur.second != -1)
	{
		cout << A[cur.first] << ' ';
		cur = nextPos[cur.first][cur.second];
	}
	return 0;
}