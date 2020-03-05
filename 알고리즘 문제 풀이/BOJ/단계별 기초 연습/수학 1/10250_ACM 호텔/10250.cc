#include<iostream>
using namespace std;

int main()
{
	int T, H, W, N;
	cin >> T;
	int roomNumber;
	while (T--)
	{
		cin >> H >> W >> N;
		if (N%H == 0)
			roomNumber = H * 100 + N / H;
		else
			roomNumber = N % H * 100 + N / H+1;
		cout << roomNumber << endl;
	}
	return 0;
}