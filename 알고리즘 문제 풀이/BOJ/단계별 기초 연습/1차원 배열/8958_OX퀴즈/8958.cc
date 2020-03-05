#include<iostream>
using namespace std;

int _strlen(char* str)
{
	int count = 0;
	for (int i = 0;; i++)
	{
		if (!str[i])
			break;
		++count;
	}
	return count;
}

int main()
{
	int N;
	cin >> N;
	int* score = new int[N];
	for (int i = 0; i < N; i++)
	{
		char* testCase = new char[80];
		cin >> testCase;
		int size = _strlen(testCase);
		score[i] = 0;
		int contiPoint = 0;
		for (int j = 0; j < size; j++)
		{
			if (testCase[j] == 'O')
				++contiPoint;
			else
				contiPoint = 0;
			score[i] += contiPoint;
		}
		delete testCase;
	}
	for (int i = 0; i < N; i++)
		cout << score[i] << endl;
	
	
	delete score;
	return 0;
}
