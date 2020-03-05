#include<iostream>
using namespace std;
int N; 
int weight[101][101] = { 0 };
int cache[101][101];

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int path(int y, int x)
{
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	if (y == N)
		return ret = 0;

	return ret = weight[y][x]+ max(path(y + 1, x), path(y + 1, x + 1));
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
			cin >> weight[i][j];
	}
	memset(cache, -1, sizeof(cache));
	cout << path(0, 0);


	return 0;
}