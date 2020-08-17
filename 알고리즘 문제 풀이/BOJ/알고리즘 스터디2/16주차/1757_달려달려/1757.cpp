#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int d[10001];
int dp[10001][501] = { 0 };//n,m

//������ ����
//1. ���� ��ġ���� �޸���.
//2. ����.
int run(int n, int m)
{
	if (n == N - m) //������ ��ġ�� �̶����� �������
		return 0;
	if (n > N - m) //�� ū ��ġ�� ���� �ȵǴ� �κе��̹Ƿ� ���� �ȵǰ� ��ȯ
		return -10000000;

	int& ret = dp[n][m];
	if (ret != 0)
		return ret;

	if (m == 0) //ù ��ġ�� �ѹ� �� ���ų� �ѹ� ��
		ret = max(run(n + 1, m + 1) + d[n], run(n + 1, 0));
	else if (0 < m && m < M) //�ѹ� �� ���ų� m��ŭ ��
		ret = max(run(n + 1, m + 1) + d[n], run(n + m, 0));
	else if (m == M) //�� ���� ������ ������ ��
		ret = run(n + m, 0);

	return ret;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> d[i];

	cout<<run(0, 0);
	return 0;
}
