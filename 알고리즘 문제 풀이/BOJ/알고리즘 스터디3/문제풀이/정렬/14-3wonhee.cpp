//1984kb, 1572ms
#include<iostream>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;
	int count[10001] = { 0 };
	int input;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		++count[input];
	}

	for (int i = 1; i < 10001; ++i)
		for (int j = 0; j < count[i]; ++j)
			cout << i << "\n";

	return 0;
}