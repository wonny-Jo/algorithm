#include<iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int burger[3];
	int drink[2];
	cin >> burger[0] >> burger[1] >> burger[2] >> drink[0] >> drink[1];
	int minBurger = min(burger[0], burger[1]);
	minBurger = min(minBurger, burger[2]);
	int minDrink = min(drink[0], drink[1]);

	cout << minBurger + minDrink - 50;

	return 0;
}