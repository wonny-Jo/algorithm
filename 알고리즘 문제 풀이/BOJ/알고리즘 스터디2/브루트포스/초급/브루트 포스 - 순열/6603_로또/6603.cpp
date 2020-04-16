#include<iostream>
#include<algorithm>
using namespace std;
int k;
int arr[14], visit[14];

void print()
{
	for (int i = 0; i < k; ++i)
	{
		if (visit[i] == 0)
			cout << arr[i]<<' ';
	}
	cout << '\n';
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	cin >> k;
	while (k != 0)
	{
		for (int i = 0; i < k; ++i)
			cin >> arr[i];

		for (int i = 0; i < 6; ++i)
			visit[i] = 0;
		for (int i = 6; i < k; ++i)
			visit[i] = 1;
		
		print();
		while (next_permutation(visit,visit+k))
			print();
		cout << '\n';
		cin >> k;
	}
	
	return 0;
}