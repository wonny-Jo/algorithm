#include<iostream>
#include<algorithm>
using namespace std;

int Count_depth;
int** data;

int max_sum()
{
	int k = Count_depth - 1;
	while (k != 0)
	{
		for (int i = 0; i < k; ++i)
			data[k - 1][i] += max(data[k][i], data[k][i + 1]);
		delete data[k];
		--k;
	}
	return data[0][0];
}

int main()
{
	cin >> Count_depth;
	data = new int*[Count_depth];
	for (int i = 0; i < Count_depth; ++i)
	{
		data[i] = new int[i + 1];
		for (int j = 0; j < i+1; ++j)
			cin >> data[i][j];
	}
	cout << max_sum();
	delete data[0];
	delete data;
	return 0;
}

