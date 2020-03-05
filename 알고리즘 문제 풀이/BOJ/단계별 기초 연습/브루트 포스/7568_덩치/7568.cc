#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int N;
	cin >> N;
	int x[51], y[51], rank[51] = { 0 };
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (x[i] < x[j] && y[i] < y[j])
				++rank[i];
		}
	}
	for (int i = 0; i < N; i++)
		cout << rank[i]+1 << " ";
	cout << endl;
	return 0;
}