#include<iostream>
using namespace std;

char sg[3] = { 'A','B','C' };
char cy[4] = { 'B','A','B','C' };
char hj[6] = { 'C','C','A','A','B','B' };

char id[3][10] = { "Adrian","Bruno","Goran" };

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int N; cin >> N;
	string correct;
	cin >> correct;
	int size = correct.size();

	int count[3] = { 0 };
	for (int i = 0; i < size; ++i)
	{
		if (correct[i] == sg[i % 3])
			++count[0];
		if (correct[i] == cy[i % 4])
			++count[1];
		if (correct[i] == hj[i % 6])
			++count[2];
	}
	int max_num = max(count[0], count[1]);
	max_num = max(max_num, count[2]);

	cout << max_num << endl;
	for (int i = 0; i < 3; ++i)
	{
		if (count[i] == max_num)
			cout << id[i] << endl;
	}
	return 0;
}