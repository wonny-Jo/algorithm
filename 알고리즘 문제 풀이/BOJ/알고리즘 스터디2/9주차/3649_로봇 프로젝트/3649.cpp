#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000001];

int main() 
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x, n;
	while (cin>>x)
	{
		cin >> n;
		x *= 10000000;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);

		int left = 0, right = n - 1;
		while (left < right)
		{
			if (arr[left] + arr[right] == x)
				break;
			else if (arr[left] + arr[right] > x)
				--right;
			else
				++left;
		}
		if (left < right)
			cout << "yes " << arr[left] << ' ' << arr[right];
		else
			cout << "danger";
		cout << '\n';
	}
	return 0;
}