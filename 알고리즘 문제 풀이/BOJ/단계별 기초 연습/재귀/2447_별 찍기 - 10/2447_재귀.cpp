#include<iostream>
using namespace std;
int N;
char arr[3000][3000];

void makeBlank(int num,int y,int x)
{
	if (num == 1)
	{
		arr[y][x] = '*';
		return;
	}

	int temp = num / 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 1 && j == 1)
				continue;
			makeBlank(temp, y + (i * temp), x + (j * temp));
		}
	}

}

void print()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << arr[i][j];
		cout << endl;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			 arr[i][j]=' ';

	makeBlank(N,0,0);
	print();

	return 0;
}