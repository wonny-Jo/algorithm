#include<iostream>
#include<algorithm>
using namespace std;
int arr[10];
bool isCheck[10];

bool check()
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		if (isCheck[i])
			sum += arr[i];
	}
	return sum == 100;
}

bool select(int cnt, int num)
{
	if (cnt == 7)
		return check();
	if (num == 9)
		return false;;

	for (int i = num; i < 9; i++)
	{
		isCheck[i] = true;
		if(select(cnt + 1, i + 1))
			return true;
		isCheck[i] = false;
	}
	return false;
}

void print()
{
	for (int i = 0; i < 9; i++)
	{
		if (isCheck[i])
			cout << arr[i] << endl;
	}
}


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	for (int i = 0; i < 9; ++i)
		cin >> arr[i];
	
	sort(arr, arr + 9);
	select(0, 0);
	print();

	return 0;
}