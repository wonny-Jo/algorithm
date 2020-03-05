#include <iostream>
using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;
	bool leakPoint[2500] = { 0 };
	int num;
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		leakPoint[num] = 1;
	}
	int count = 0;
	for (int i = 1; i <= 1000; ++i)
	{
		if (leakPoint[i])
		{
			++count;
			for (int j = 0; j < L; ++j)
				leakPoint[i + j] = 0;
		}
	}
	cout << count;
	return 0;
}