#include<iostream>
using namespace std;

char DNA_char[4] = { 'A','C','G','T' };

int main()
{
	string DNA[1001];
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> DNA[i];
	int count[51][4] = { 0 }; //ATGC
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (DNA[j][i] == 'A')
				++count[i][0];
			else if (DNA[j][i] == 'C')
				++count[i][1];
			else if (DNA[j][i] == 'G')
				++count[i][2];
			else if (DNA[j][i] == 'T')
				++count[i][3];
		}
	}

	int maxCountNumber[1001] = { 0 };
	int temp1,temp2;
	for (int i = 0; i < M; ++i)
	{
		if (count[i][0] < count[i][1]) temp1 = 1;
		else temp1 = 0;
		if (count[i][2] < count[i][3]) temp2 = 3;
		else temp2 = 2;
		if (count[i][temp1] < count[i][temp2]) maxCountNumber[i] = temp2;
		else maxCountNumber[i] = temp1;
	}

	for (int i = 0; i < M; ++i)
		cout << DNA_char[maxCountNumber[i]];
	int sumDistance = 0;
	for (int i = 0; i < M; ++i)
		sumDistance += N - count[i][maxCountNumber[i]];
	cout << endl << sumDistance << endl;
	return 0;
}