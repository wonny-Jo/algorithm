#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int arr[101];
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 2; i <= arr[1]; ++i) //arr[1]까지 보는게 킬포
	{
		bool isTrue = true;
		for (int j = 0; j < N - 1; ++j)
		{
			if (arr[j] % i != arr[j + 1] % i)
			{
				isTrue = false;
				break;
			}
		}
		if (isTrue)
			cout << i << ' ';
	}
	return 0;
}