#include<iostream>
using namespace std;

int main()
{
	int C;
	cin >> C;
	int N;
	double average, overNum;
	int *arr;
	for (int i = 0;  i < C; i++)
	{
		cin >> N;
		arr = new int[N];
		average = 0; overNum = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
			average += arr[j];
		}
		average /= N;
		for (int j = 0; j < N; j++)
		{
			if (average < arr[j])
				++overNum;
		}
		cout<<fixed;
		cout.precision(3);
		cout << (overNum / N)*100<<"%" << endl;
		delete arr;
	}

	return 0;
}