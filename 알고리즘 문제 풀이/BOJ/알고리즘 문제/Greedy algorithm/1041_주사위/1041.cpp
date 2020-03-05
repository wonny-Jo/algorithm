#include<iostream>
#include<algorithm>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	long long N, dice[6];
	cin >> N;
	for (int i = 0; i < 6; ++i)
		cin >> dice[i];
	
	if (N == 1)
	{
		sort(dice, dice + 6);
		cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
		return 0;
	}
	long long face1 = 5 * (N - 2) * (N - 2) + 4 * (N - 2);
	long long face2 = 8*N - 12;
	long long face3 = 4;
	if (N == 2)
		face1 = 0;

	long long sum_face1_number;
	long long sum_face2_number;
	long long sum_face3_number;
	long long Min[3];
	Min[0] = min(dice[0], dice[5]);
	Min[1] = min(dice[1], dice[4]);
	Min[2] = min(dice[2], dice[3]);
	sort(Min, Min + 3);
	sum_face3_number = Min[0] + Min[1] + Min[2];
	sum_face2_number = Min[0] + Min[1];
	sum_face1_number = Min[0];

	cout << face1 * sum_face1_number + face2 * sum_face2_number + face3 * sum_face3_number;
	
	return 0;
}