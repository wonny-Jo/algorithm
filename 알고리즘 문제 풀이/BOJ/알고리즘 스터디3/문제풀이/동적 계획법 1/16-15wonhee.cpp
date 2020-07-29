//2376kb, 4ms
#include<iostream>
#include<algorithm>
using namespace std;
int num[100001];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int sum = 0, result = -10000;

	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
		sum += num[i];
		result = max(result, sum);
		if (sum < 0)
			sum = 0;
	}
	cout << result;
	return 0;
}