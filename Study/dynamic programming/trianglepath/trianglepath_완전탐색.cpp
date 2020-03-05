#include<iostream>
using namespace std;
int N; 
int weight[101][101] = { 0 };

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int path(int y, int x)
{
	if (y == N)
		return 0;

	return max(weight[y][x] + path(y + 1, x), weight[y][x] + path(y + 1, x + 1));
}


int main()
{

	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
			cin >> weight[i][j];
	}
	cout << path(0, 0);


	return 0;
}