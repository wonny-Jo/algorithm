#include<iostream>
using namespace std;
int N;
int block[101][101];

bool isRange(int y, int x)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;
	return true;
}


bool jump(int y, int x)
{
	if (!isRange(y, x))
		return false;
	if (y == N - 1 && x == N - 1)
		return true;

	if (jump(y + block[y][x], x))
		return true;
	else if (jump(y, x + block[y][x]))
		return true;
	return false;
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> block[i][j];
	}
	cout << jump(0, 0);
	return 0;
}