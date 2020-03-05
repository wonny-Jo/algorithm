#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int count[10001] = { 0 };
	int input;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		++count[input];
	}

	for (int i = 1; i < 10001; ++i)
	{
		for (int j = 0; j < count[i]; ++j)
			cout << i << "\n";
	}

	return 0;
}