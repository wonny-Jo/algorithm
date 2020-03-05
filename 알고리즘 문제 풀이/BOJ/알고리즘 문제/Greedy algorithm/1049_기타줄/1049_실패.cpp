#include<iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int Minpackage = 1000;
	int MinOnePrice = 1000;
	int temp;
	for (int i = 0; i < M; ++i)
	{
		cin >> temp;
		if (temp < Minpackage)
			Minpackage = temp;
		cin >> temp;
		if (temp < MinOnePrice)
			MinOnePrice = temp;
	}
	int sum = 0;
	if (Minpackage < 6 * MinOnePrice)
	{
		sum += Minpackage * (N / 6);
		if (Minpackage < (N & 6) * MinOnePrice)
			sum += Minpackage;
		else
			sum += MinOnePrice * (N % 6);
	}
	else
		sum = MinOnePrice * N;
	cout << sum;
	return 0;
}