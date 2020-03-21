#include<iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	int cnt = 0;
	for (int i = 5; i <= N; i+=5)
	{
		int num = i;
		while (num %5==0)
		{
			num /= 5;
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}