//1974kb, 0ms
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int num; cin >> num;
	char arr[11];
	int i = 0;
	while (num > 0)
	{
		arr[i] = (num % 10) + '0';
		num /= 10;
		++i;
	}
	sort(arr, arr + i);

	for (int j = i - 1; j >= 0; --j)
		cout << arr[j];

	return 0;
}