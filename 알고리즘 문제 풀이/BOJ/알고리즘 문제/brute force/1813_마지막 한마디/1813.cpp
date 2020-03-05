#include<iostream>
using namespace std;

int main()
{
	int count[100001] = { 0 };
	int N; cin >> N;
	int input;
	for (int i = 0; i < N; ++i)
	{
		cin >> input; 
		++count[input];
	}

	for (int i = N; i >=0; --i)
	{
		if (i == count[i])
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}