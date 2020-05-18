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

// ���� �� �κ����� ������, �� �κ��� �� ���� ����� ����
vector<int> sum1;
vector<int> sum2;

// �� �������� �������� ���� �� ���� �κ� �� ���� ���
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

// �� �������� �������� ������ �Ʒ� ���� �κ� �� ���� ���
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

// �� �������� �������� ������ �� ���� �κ� �� ���� ���
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

// �� �������� �������� ���� �Ʒ��� ���� �κ� �� ���� ���
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

	// N x N �� ���� ���� ���� �� �ִ� �������� (N-1) x (N-1) �� �̴�
	for (int i = 0; i < row - 1; i++)
	{
		for (int j = 0; j < row - 1; j++)
		{
			// �� �������� �������� ���� ��, ������ �Ʒ� ������ ���� �� �κ� �� ���
			calLeftUp(i, j);
			calRightDown(i + 1, j + 1);

			vector<int>::iterator iter1;
			vector<int>::iterator iter2;

			// ���� �κ� �� ���߿� ���� ���� �ִٸ�, ī��Ʈ 1 ����
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

			// �� �������� �������� ������ ��, ���� �Ʒ��� ������ ���� �� �κ� �� ���
			calRightUp(i, j + 1);
			calLeftDown(i + 1, j);

			// ���� �κ� �� ���߿� ���� ���� �ִٸ�, ī��Ʈ 1 ����
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