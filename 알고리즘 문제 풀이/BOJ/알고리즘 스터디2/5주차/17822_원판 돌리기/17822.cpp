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
			//돌려 돌려 원판
			if ((i + 1) % x == 0)
			{
				if (d == 0)//시계방향
					for (int j = 0; j < k; j++)
					{
						dq[i].push_front(dq[i].back());
						dq[i].pop_back();
					}
				else//반시계방향
					for (int j = 0; j < k; j++)
					{
						dq[i].push_back(dq[i].front());
						dq[i].pop_front();
					}
			}
		}

		bool c[51][51] = { 0 };
		//한 원판 내에서 인접한 것들 제거. 값을 0으로 표시
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

		//원판 간에 인접한것들 제거. 값을 0으로 표시하자
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

		bool isSame = false; //같은 경우가 있는지 체크
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
			//평균 구하기
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
			//연산
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