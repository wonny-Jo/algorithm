#include<iostream>
#include<deque>
using namespace std;
deque<double> dq[51];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);
	
	int N, M, T; cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			double a; cin >> a;
			dq[i].push_back(a);
		}

	for (int a = 0; a < T; a++)
	{
		int x, d, k; cin >> x >> d >> k;
		for (int i = 0; i < N; i++)
		{
			//���� ���� ����
			if ((i + 1) % x == 0)
			{
				if (d == 0)//�ð����
					for (int j = 0; j < k; j++)
					{
						dq[i].push_front(dq[i].back());
						dq[i].pop_back();
					}
				else//�ݽð����
					for (int j = 0; j < k; j++)
					{
						dq[i].push_back(dq[i].front());
						dq[i].pop_front();
					}
			}
		}

		bool c[51][51] = { 0 };
		//�� ���� ������ ������ �͵� ����. ���� 0���� ǥ��
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M - 1; j++)
			{
				if (dq[i][j]!=0&&dq[i][j] == dq[i][j + 1])
				{
					c[i][j] = 1; c[i][j + 1] = 1;
				}
			}
			if (dq[i][M - 1] != 0 && dq[i][M - 1] == dq[i][0])
			{
				c[i][M - 1] = 1; c[i][0] = 1;
			}
		}

		//���� ���� �����Ѱ͵� ����. ���� 0���� ǥ������
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N-1; j++)
			{
				if (dq[j][i] != 0 && dq[j][i] == dq[j+1][i])
				{
					c[j][i] = 1; c[j + 1][i] = 1;
				}
			}
		}

		bool isSame = false; //���� ��찡 �ִ��� üũ
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (c[i][j])
				{
					isSame = true;
					dq[i][j] = 0;
				}
			}
		}
		 
		if (!isSame)
		{
			//��� ���ϱ�
			double ave = 0, cnt = 0;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (dq[i][j] != 0)
					{
						ave += dq[i][j];
						++cnt;
					}
				}
			}
			ave /= cnt;
			//����
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (dq[i][j] != 0)
					{
						if (dq[i][j] > ave) --dq[i][j];
						else if (dq[i][j] < ave) ++dq[i][j];
					}
				}
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ret += dq[i][j];
	cout << ret;

	return 0;
}