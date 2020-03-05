#include<iostream>
using namespace std;
int N;
int block[101][101];
int cache[101][101] = { -1 };

bool isRange(int y, int x)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;
	return true;
}


int jump(int y, int x)
{
	if (!isRange(y, x))
		return 0;
	if (y == N - 1 && x == N - 1)
		return 1;

	int& ret = cache[y][x];
	if (ret!= -1)
		return ret;

	return ret = (jump(y + block[y][x], x) || jump(y, x + block[y][x]));
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