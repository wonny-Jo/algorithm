#include<iostream>
using namespace std;

int** rotate90(int** arr, int N)
{
	int** output = new int* [N];
	for (int i = 0; i < N; i++)
		output[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			output[j][N - 1 - i] = arr[i][j];
	return output;
}

int** rotate180(int** arr, int N)
{
	int** output = new int* [N];
	for (int i = 0; i < N; i++)
		output[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			output[N - i - 1][N - j - 1] = arr[i][j];
	return output;
}

int** rotate270(int** arr, int N)
{
	int** output = new int* [N];
	for (int i = 0; i < N; i++)
		output[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			output[N - j - 1][i] = arr[i][j];
	return output;
}

void print(int** arr90, int** arr180, int** arr270, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr90[i][j];
		cout << " ";
		for (int j = 0; j < N; j++)
			cout << arr180[i][j];
		cout << " ";
		for (int j = 0; j < N; j++)
			cout << arr270[i][j];
		cout << endl;
	}
}

int main()
{
	int T, N;
	int** input;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		input = new int* [N];
		for (int i = 0; i < N; i++)
			input[i] = new int[N];
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				cin >> input[j][k];
		cout << "#" << i + 1 << endl;
		print(rotate90(input, N), rotate180(input, N), rotate270(input, N), N);
	}
	return 0;
}