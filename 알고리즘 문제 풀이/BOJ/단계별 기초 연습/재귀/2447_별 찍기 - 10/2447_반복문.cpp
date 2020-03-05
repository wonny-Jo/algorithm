#include<iostream>
using namespace std;
int N;
char arr[3000][3000];
void checkBlank(int y,int x)
{
	int temp_y = y, temp_x = x;
	while (temp_y!=0&&temp_x!=0)
	{
		if (temp_y % 3 == 1 && temp_x % 3 == 1)
		{
			arr[y][x] = ' ';
			break;
		}
		temp_y /= 3; temp_x /= 3;
	}
}

void makeBlank()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			checkBlank(i, j);
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
			arr[i][j] = '*';
	makeBlank();
	print();

	return 0;
}