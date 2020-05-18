#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int row;
int col;

int arr[51][51];
int cache[51][51];

// 땅을 두 부분으로 나눌때, 각 부분의 합 들이 저장될 벡터
vector<int> sum1;
vector<int> sum2;

// 한 꼭지점을 기준으로 왼쪽 위 땅의 부분 합 들을 계산
void calLeftUp(int x, int y)
{
	for (int i = x; i >= 0; i--)
	{
		int rowSum = 0;
		for (int j = y; j >= 0; j--)
		{
			rowSum += arr[i][j];

			if (i != x)
				cache[i][j] = cache[i + 1][j] + rowSum;
			else
				cache[i][j] = rowSum;

			sum1.push_back(cache[i][j]);
		}
	}
}

// 한 꼭지점을 기준으로 오른쪽 아래 땅의 부분 합 들을 계산
void calRightDown(int x, int y)
{

	for (int i = x; i < row; i++)
	{
		int rowSum = 0;
		for (int j = y; j < col; j++)
		{
			rowSum += arr[i][j];

			if (i != x)
				cache[i][j] = cache[i - 1][j] + rowSum;
			else
				cache[i][j] = rowSum;

			sum2.push_back(cache[i][j]);
		}
	}

}

// 한 꼭지점을 기준으로 오른쪽 위 땅의 부분 합 들을 계산
void calRightUp(int x, int y)
{

	for (int i = x; i >= 0; i--)
	{
		int rowSum = 0;
		for (int j = y; j < col; j++)
		{
			rowSum += arr[i][j];

			if (i != x)
				cache[i][j] = cache[i + 1][j] + rowSum;
			else
				cache[i][j] = rowSum;

			sum1.push_back(cache[i][j]);
		}
	}

}

// 한 꼭지점을 기준으로 왼쪽 아래의 땅의 부분 합 들을 계산
void calLeftDown(int x, int y)
{

	for (int i = x; i < row; i++)
	{
		int rowSum = 0;
		for (int j = y; j >= 0; j--)
		{
			rowSum += arr[i][j];

			if (i != x)
				cache[i][j] = cache[i - 1][j] + rowSum;
			else
				cache[i][j] = rowSum;

			sum2.push_back(cache[i][j]);
		}
	}

}

void solve()
{
	int sum = 0;

	// N x N 땅 에서 땅을 나눌 수 있는 꼭지점은 (N-1) x (N-1) 개 이다
	for (int i = 0; i < row - 1; i++)
	{
		for (int j = 0; j < row - 1; j++)
		{
			// 한 꼭지점을 기준으로 왼쪽 위, 오른쪽 아래 땅으로 나눈 후 부분 합 계산
			calLeftUp(i, j);
			calRightDown(i + 1, j + 1);

			vector<int>::iterator iter1;
			vector<int>::iterator iter2;

			// 땅의 부분 합 들중에 같은 땅이 있다면, 카운트 1 증가
			for (int a = 0; a < sum1.size(); a++)
			{
				for (int b = 0; b < sum2.size(); b++)
				{
					if (sum1[a] == sum2[b])
						sum++;
				}
			}

			sum1.clear();
			sum2.clear();

			// 한 꼭지점을 기준으로 오른쪽 위, 왼쪽 아래의 땅으로 나눈 후 부분 합 계산
			calRightUp(i, j + 1);
			calLeftDown(i + 1, j);

			// 땅의 부분 합 들중에 같은 땅이 있다면, 카운트 1 증가
			for (int a = 0; a < sum1.size(); a++)
			{
				for (int b = 0; b < sum2.size(); b++)
				{
					if (sum1[a] == sum2[b])
						sum++;
				}
			}
			sum1.clear();
			sum2.clear();
		}
	}

	cout << sum << endl;
}

int main() {
	cin >> row;
	col = row;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < row; j++)
			cin >> arr[i][j];

	solve();

	return 0;
}