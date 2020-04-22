#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int arr[101][101] = { 0 };
int INF = 1000000000;

void print()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == INF) arr[i][j] = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}

void floydwarshall()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; j++)
			if(i!=j) arr[i][j] = INF;

	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		if (arr[a][b] == 0 || arr[a][b] > c)
			arr[a][b] = c;
	}

	floydwarshall();
	print();

	return 0;
}